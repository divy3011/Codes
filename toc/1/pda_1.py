stack = []
inputString = input('Enter input String: ')
inputString = inputString.rstrip()
states = ['q0','q1','q2','qf']
input_symbols = ['a','b','c']
stack_symbols = ['z','a','b']
initial_state = 'q0'
initial_stack = 'z'
final_states = ['qf']
productions = [['q0','a','z','q0','az'],['q0','a','a','q0','aa'],['q0','b','a','q1','e'],['q1','b','a','q1','e'],['q1','b','z','q1','bz'],['q1','b','b','q1','bb'],['q1','c','b','q2','e'],['q2','c','b','q2','e'],['q2','e','z','qf','z']]
print('Productions List:')
for production in productions:
    print('\t', production)
print('Transition Table is :')
inputString += 'e'
initStackSymbol = initial_stack
stack.append(initStackSymbol)
finalStates = final_states
stackSymbols = stack_symbols
currentStackSymbol = initStackSymbol
currentState = initial_state
print('State\tInput\tStack\tMove')
print('{}\t {}\t {}\t ({}, {})'.format(currentState, '_', 'Z', currentStackSymbol, stack))
for char in inputString:
    for production in productions:
        if ((production[0] == currentState) and (production[1] == char) and (production[2] == currentStackSymbol)):
            currentState = production[3]
            if(len(production[4]) == 2):
                stack.append(char)
            elif(len(production[4]) == 3):
                stack.append(char)
                stack.append(char)
            elif ((production[4] == 'e') and (len(stack) != 1)):
                stack.pop()
                break
    previousStackSymbol = currentStackSymbol
    currentStackSymbol = stack[len(stack)-1]
    print('{}\t {}\t {}\t ({}, {})'.format(currentState, char, previousStackSymbol, currentStackSymbol, stack))
if(currentState in finalStates):
    print('String accepted by PDA:)')
else:
    print('String rejected by PDA:(')