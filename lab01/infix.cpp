char prec( char input ){
        int position;
        if ( input == '*' || input == '/')
                position = 1;
        else if ( input == '+' || input == '-')
                position = 2;

        return position;
}
int main(){
    stack <char> operators;
    char input;
    cout << "Enter the equation you want to convert to postfix.\n";
    cin >> input;
    while(!cin.eof()){
        if((input >= 'a' && input <= 'z') || (input >= '1' && input <= '9') || (input >= 'A' && input <= 'Z') )
            cout << input;
        else{
            if (input == '(') // '(' has lowest precedence in the stack, highest outside
                operators.push(input);
            else if (input == ')'){
                while (!operators.empty() && operators.top() != '('){
                    cout << operators.top();
                    operators.pop();
                }
                if (!operators.empty())
                    operators.pop();
                else
                    cout << "Error, there was no matching '(' \n"; //error no matching '('
            } else if ( input ==  '*' || input == '/' || input == '+' || input == '-') {
                if (operators.empty() || prec(operators.top()) < prec(input)) // bottom of stack has lower precedence than everything
                    operators.push(input);
                else{// if(prec(operators.top()) >= prec(input)) // prec(top of stack) >= prec(input
                    while (!operators.empty() && prec(operators.top()) >= prec(input)){
                        cout << operators.top();
                        operators.pop();
                    }
                    operators.push(input);
                }
            } else //check for errors
                cout << " ERROR \n ";//check for errors
        }
        cin >> input;
    }
    while(operators.top() != '\0'){ // While stack isn't empty
        cout << operators.top();
        operators.pop();
    }
}//main 