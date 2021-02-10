pda_stack = []
inputString = input('Please, enter input string: ')
inputString = inputString.rstrip()
states = ['q0','q1','q2','qf']
input_symbols = ['a','b','c']
pda_stack_symbols = ['z','a','b']
initial_state = 'q0'
initial_pda_stack = 'z'
final_states = ['qf']
productions = [['q0','a','z','q0','az'],['q0','a','a','q0','aa'],['q0','b','a','q1','e'],['q1','b','a','q1','e'],['q1','b','z','q1','bz'],['q1','b','b','q1','bb'],['q1','c','b','q2','e'],['q2','c','b','q2','e'],['q2','e','z','qf','z']]
print('Transition Table is:')
inputString += 'e'
initial_stack_symbolmbol = initial_pda_stack
pda_stack.append(initial_stack_symbolmbol)
currentStackSymbol = initial_stack_symbolmbol
previousState = initial_state
currentState = initial_state
print('input symbol\tfrom State\tTo State\tStack')
for input_element in inputString:
    for production in productions:
        if ((production[0] == currentState) and (production[1] == input_element) and (production[2] == currentStackSymbol)):
            currentState = production[3]
            if(len(production[4]) == 2):
                pda_stack.append(input_element)
            elif(len(production[4]) == 3):
                pda_stack.append(input_element)
                pda_stack.append(input_element)
            elif ((production[4] == 'e') and (len(pda_stack) != 1)):
                pda_stack.pop()
                break
    previousStackSymbol = currentStackSymbol
    currentStackSymbol = pda_stack[len(pda_stack)-1]
    print('  {}\t   {}\t\t   {}\t      {}'.format(input_element, previousState, currentState, pda_stack))
    previousState = currentState
if(currentState in final_states):
    print('String accepted by PDA')
else:
    print('String rejected by PDA')