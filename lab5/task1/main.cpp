/* Zaprogramuj algorytm stacji rozrządowej Dijkstry, ktory 
 * przeksztalca wyrazenie arytmetyczne z postaci infiksowej z 
 * nawiasami do postaci postfiksowej bez nawiasow (Odwrotna Notacja 
 * Polska). Wykorzystaj do tego celu kolekcje standardowe.
 * W swoim algorytmie najpierw podziel wejsciowe wyrazenie 
 * arytmetyczne na kolejke/liste leksemow. Wynikiem dzialania 
 * procedury przeksztalcajacej ma byc kolejka/lista symboli.
 */

#include <string>
#include <cctype>
#include <unordered_map>
#include <list>
#include <iostream>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

enum class tok_t: size_t {
    num,
    lparen,
    rparen,
    add,
    sub,
    div,
    mul,
};

using token = pair<tok_t, string>;

auto inline is_operator(const token &t){
    return t.first == tok_t::add ||
        t.first == tok_t::sub ||
        t.first == tok_t::div ||
        t.first == tok_t::mul;
}

auto tokenize(const string &s){

    const unordered_map<char, tok_t> allowed_not_nums{
        {'+', tok_t::add},
        {'-', tok_t::sub}, 
        {'/', tok_t::div},
        {'*', tok_t::mul},
        {'(', tok_t::lparen},
        {')', tok_t::rparen},
    };
    list<token> l; // na stosie i ja to zwracam? RVO ?
    
    for (auto it = s.begin(); it != s.end(); ){
        if(*it == ' '){
            ++it;
            continue;
        }

        auto tok_begin = it; // copy
        bool is_digit = isdigit(*it);
        tok_t tok_type;
        if(is_digit){
            tok_type = tok_t::num;
            while(it != s.end() && *it != ' ' && isdigit(*it)){
                ++it;
            }
        } else {
            auto tok = allowed_not_nums.find(*it);
            if(tok == allowed_not_nums.end())
                throw "wrong expression";

            tok_type = tok->second;
            ++it;
        }

        l.push_back({tok_type, string(tok_begin, it)});
    }

    return l;
}

auto shunting_yard(const list<token> &l){
//while there are tokens to be read do:
//    read a token.
//    if the token is a number, then:
//        push it to the output queue.
//    if the token is a function then:
//        push it onto the operator stack 
//    if the token is an operator, then:
//        while ((there is a function at the top of the operator stack)
//               or (there is an operator at the top of the operator stack with greater precedence)
//               or (the operator at the top of the operator stack has equal precedence and is left associative))
//              and (the operator at the top of the operator stack is not a left parenthesis):
//            pop operators from the operator stack onto the output queue.
//        push it onto the operator stack.
//    if the token is a left paren (i.e. "("), then:
//        push it onto the operator stack.
//    if the token is a right paren (i.e. ")"), then:
//        while the operator at the top of the operator stack is not a left paren:
//            pop the operator from the operator stack onto the output queue.
//        /* if the stack runs out without finding a left paren, then there are mismatched parentheses. */
//        if there is a left paren at the top of the operator stack, then:
//            pop the operator from the operator stack and discard it
//after while loop, if operator stack not null, pop everything to output queue
//if there are no more tokens to read then:
//    while there are still operator tokens on the stack:
//        /* if the operator token on the top of the stack is a paren, then there are mismatched parentheses. */
//        pop the operator from the operator stack onto the output queue.
//exit.
    
    queue<token> output_q;
    stack<token> operator_s;
    
    for(const auto &tok : l){
        if(tok.first == tok_t::num)
            output_q.push(tok);
        
        if(is_operator(tok) || tok.first == tok_t::lparen)
            operator_s.push(tok); 

        if(tok.first == tok_t::rparen){
            while(operator_s.top().first != tok_t::lparen){
                output_q.push(operator_s.top());
                operator_s.pop();
            }
            if(operator_s.top().first == tok_t::lparen){
                operator_s.pop();
            }
        }
    }
    
    while(!operator_s.empty()){
        output_q.push(operator_s.top());
        operator_s.pop();
    }
    
    return output_q;

}


int main(){
    string x = "1123 + 22*(23+3222)  "; 
    auto tok_list = tokenize(x);

    cout << x << "\n";

    auto output = shunting_yard(tok_list);

    while(!output.empty()){
        cout << output.front().second << " ";
        output.pop();
    }

    return 0;
}
