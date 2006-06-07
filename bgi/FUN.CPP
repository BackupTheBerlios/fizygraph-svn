double f(double x, int kl, int kp){
	double n1 = 0, n2 = 0, d = 0;
	int i = kl, l = 0, p = 0, il = 0, ip = 0;
	while(i < kp){
		switch(int(fun[i])){

			//-----> +:
			case int('+'):
			l = ++i;
			i++;
			il++;
			while(il != ip){
				i++;
				if(fun[i] == '['){
					il++;
				}
				if(fun[i] == ']'){
					ip++;
				}
			}
			p = i;
			n1 = f(x,l,p);
			l = ++i;
			i++;
			il++;
			while(il != ip){
				i++;
				if(fun[i] == '['){
					il++;
				}
				if(fun[i] == ']'){
					ip++;
				}
			}
			p = i;
			n2 = f(x,l,p);
			d = n1 + n2;
			break;

			//-----> -:
			case int('-'):
			l = ++i;
			i++;
			il++;
			while(il != ip){
				i++;
				if(fun[i] == '['){
					il++;
				}
				if(fun[i] == ']'){
					ip++;
				}
			}
			p = i;
			n1 = f(x,l,p);
			l = ++i;
			i++;
			il++;
			while(il != ip){
				i++;
				if(fun[i] == '['){
					il++;
				}
				if(fun[i] == ']'){
					ip++;
				}
			}
			p = i;
			n2 = f(x,l,p);
			d = n1 - n2;
			break;

			//-----> *:
			case int('*'):
			l = ++i;
			i++;
			il++;
			while(il != ip){
				i++;
				if(fun[i] == '['){
					il++;
				}
				if(fun[i] == ']'){
					ip++;
				}
			}
			p = i;
			n1 = f(x,l,p);
			l = ++i;
			i++;
			il++;
			while(il != ip){
				i++;
				if(fun[i] == '['){
					il++;
				}
				if(fun[i] == ']'){
					ip++;
				}
			}
			p = i;
			n2 = f(x,l,p);
			d = n1 * n2;
			break;

			//-----> /:
			case int('/'):
			l = ++i;
			i++;
			il++;
			while(il != ip){
				i++;
				if(fun[i] == '['){
					il++;
				}
				if(fun[i] == ']'){
					ip++;
				}
			}
			p = i;
			n1 = f(x,l,p);
			l = ++i;
			i++;
			il++;
			while(il != ip){
				i++;
				if(fun[i] == '['){
					il++;
				}
				if(fun[i] == ']'){
					ip++;
				}
			}
			p = i;
			n2 = f(x,l,p);
			if(n2 != 0){
				d = n1 / n2;
			}
			else{
			}
			break;

			//-----> liczby:
			case int('x'):
			d = x;
			break;

			case int('0'):
			d = 0;
			break;

			case int('1'):
			d = 1;
			break;

			case int('2'):
			d = 2;
			break;

			case int('3'):
			d = 3;
			break;

			case int('4'):
			d = 4;
			break;

			case int('5'):
			d = 5;
			break;

			case int('6'):
			d = 6;
			break;

			case int('7'):
			d = 7;
			break;

			case int('8'):
			d = 8;
			break;

			case int('9'):
			d = 9;
			break;

			case int('Z'):
			d = 3.141592654;
			break;

			//----------> funkcje:

			//-----> ACOS:
			case int('G'):
			l = ++i;
			i++;
			il++;
			while(il != ip){
				i++;
				if(fun[i] == '('){
					il++;
				}
				if(fun[i] == ')'){
					ip++;
				}
			}
			p = i;
			n1 = f(x,l,p);
			d = acos(n1);
			break;

			//-----> ASIN:
			case int('H'):
			l = ++i;
			i++;
			il++;
			while(il != ip){
				i++;
				if(fun[i] == '('){
					il++;
				}
				if(fun[i] == ')'){
					ip++;
				}
			}
			p = i;
			n1 = f(x,l,p);
			d = asin(n1);
			break;

			//-----> ATAN:
			case int('I'):
			l = ++i;
			i++;
			il++;
			while(il != ip){
				i++;
				if(fun[i] == '('){
					il++;
				}
				if(fun[i] == ')'){
					ip++;
				}
			}
			p = i;
			n1 = f(x,l,p);
			d = atan(n1);
			break;

			//-----> COS:
			case int('C'):
			l = ++i;
			i++;
			il++;
			while(il != ip){
				i++;
				if(fun[i] == '('){
					il++;
				}
				if(fun[i] == ')'){
					ip++;
				}
			}
			p = i;
			n1 = f(x,l,p);
			d = cos(n1);
			break;

			//-----> COSH:
			case int('D'):
			l = ++i;
			i++;
			il++;
			while(il != ip){
				i++;
				if(fun[i] == '('){
					il++;
				}
				if(fun[i] == ')'){
					ip++;
				}
			}
			p = i;
			n1 = f(x,l,p);
			d = cosh(n1);
			break;

			//-----> EXP:
			case int('E'):
			l = ++i;
			i++;
			il++;
			while(il != ip){
				i++;
				if(fun[i] == '('){
					il++;
				}
				if(fun[i] == ')'){
					ip++;
				}
			}
			p = i;
			n1 = f(x,l,p);
			d = exp(n1);
			break;

			//-----> LOG:
			case int('L'):
			l = ++i;
			i++;
			il++;
			while(il != ip){
				i++;
				if(fun[i] == '('){
					il++;
				}
				if(fun[i] == ')'){
					ip++;
				}
			}
			p = i;
			n1 = f(x,l,p);
			d = log(n1);
			break;

			//-----> LOG10:
			case int('N'):
			l = ++i;
			i++;
			il++;
			while(il != ip){
				i++;
				if(fun[i] == '('){
					il++;
				}
				if(fun[i] == ')'){
					ip++;
				}
			}
			p = i;
			n1 = f(x,l,p);
			d = log10(n1);
			break;

			//-----> SIN:
			case int('S'):
			l = ++i;
			i++;
			il++;
			while(il != ip){
				i++;
				if(fun[i] == '('){
					il++;
				}
				if(fun[i] == ')'){
					ip++;
				}
			}
			p = i;
			n1 = f(x,l,p);
			d = sin(n1);
			break;

			//-----> SINH:
			case int('U'):
			l = ++i;
			i++;
			il++;
			while(il != ip){
				i++;
				if(fun[i] == '('){
					il++;
				}
				if(fun[i] == ')'){
					ip++;
				}
			}
			p = i;
			n1 = f(x,l,p);
			d = sinh(n1);
			break;

			//-----> TAN:
			case int('T'):
			l = ++i;
			i++;
			il++;
			while(il != ip){
				i++;
				if(fun[i] == '('){
					il++;
				}
				if(fun[i] == ')'){
					ip++;
				}
			}
			p = i;
			n1 = f(x,l,p);
			d = tan(n1);
			break;

			//-----> TANH:
			case int('W'):
			l = ++i;
			i++;
			il++;
			while(il != ip){
				i++;
				if(fun[i] == '('){
					il++;
				}
				if(fun[i] == ')'){
					ip++;
				}
			}
			p = i;
			n1 = f(x,l,p);
			d = tanh(n1);
			break;

			//-----> FABS:
			case int('M'):
			l = ++i;
			i++;
			il++;
			while(il != ip){
				i++;
				if(fun[i] == '('){
					il++;
				}
				if(fun[i] == ')'){
					ip++;
				}
			}
			p = i;
			n1 = f(x,l,p);
			d = fabs(n1);
			break;

			//-----> SQRT:
			case int('P'):
			l = ++i;
			i++;
			il++;
			while(il != ip){
				i++;
				if(fun[i] == '('){
					il++;
				}
				if(fun[i] == ')'){
					ip++;
				}
			}
			p = i;
			n1 = f(x,l,p);
			d = sqrt(n1);
			break;

			/*default:
			cout << "\n\nNie rozpoznaje znaku w funkcji!";
			cout << "\nFunkcja moze zostac zle zinterpretowana.\n";
			system("PAUSE");
			return 0;
			break;*/
		}
	i++;
	}
return d;
}

