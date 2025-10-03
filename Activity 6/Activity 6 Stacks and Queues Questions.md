# Question 1

PUSH(S,4)
S.top becomes 1
S[1] = 4

S:  [4,  ,  ,  ,  ,  ]
      ↑
   S.top = 1



PUSH(S,1)
S.top becomes 2
S[2] = 1

S:  [4, 1,  ,  ,  ,  ]
         ↑
      S.top = 2



PUSH(S,3)
S.top becomes 3
S[3] = 3

S:  [4, 1, 3,  ,  ,  ]
              ↑
           S.top = 3



POP(S)
Remove top element 3
S.top becomes 2

S:  [4, 1, 3,  ,  ,  ]
         ↑
      S.top = 2
	
	
	
	PUSH(S,8)
	S.top becomes 3
	S[3] = 8
	
	S:  [4, 1, 8,  ,  ,  ]
              ↑
           S.top = 3



POP(S)
Remove top element 8
S.top becomes 2

S:  [4, 1, 8,  ,  ,  ]
         ↑
      S.top = 2




	S = [4, 1, 8, , , ]


# Question 2
 
ENQUEUE(Q,4)
Q.tail = 1
Q[1] = 4

Q:  [4, _, _, _, _, _]
     ↑
   head=1
     ↑
   tail=1



ENQUEUE(Q,1)
Q.tail = 2
Q[2] = 1

Q:  [4, 1, _, _, _, _]
     ↑
   head=1
         ↑
       tail=2



ENQUEUE(Q,3)
	Q.tail = 3
Q[2] = 3

Q:  [4, 1, 3, _, _, _]
     ↑
   head=1
              ↑
            tail=3



DEQUEUE(Q)
Remove Q[1]
Q.head = 2

Q:  [4, 1, 3, _, _, _]
         ↑
       head=2
              ↑
            tail=3



ENQUEUE(Q,3)
Q.tail = 4
Q[4] = 8

Q:  [4, 1, 3, 8, _, _]
         ↑
       head=2
                   ↑
                tail=4



DEQUEUE(Q)
	Remove Q[2] (value = 1)
Q.head = 3

Q:  [4, 1, 3, 8, _, _]
              ↑
            head=3
                   ↑
                tail=4


Q = [4, 1, 3, 8, _, _]



# Question 3
 
ENQUEUE(Q,x) with overflow detection

  if (Q.tail + 1 == Q.head) or (Q.tail == Q.length and Q.head == 1)
      error "overflow"
  Q[Q.tail] = x
  if Q.tail == Q.length
      Q.tail = 1
  else 
      Q.tail = Q.tail + 1



DEQUEUE(Q) with underflow detection

  if Q.head == Q.tail
      error "underflow"
  x = Q[Q.head]
  if Q.head == Q.length
      Q.head = 1
  else 
      Q.head = Q.head + 1
  return x



# Question 4

PUSH-FRONT(deque, x)
  if deque is full
      error "overflow"
  if deque.head == 1
      deque.head = deque.length
  else
      deque.head = deque.head - 1
  deque[deque.head] = x



	POP-FRONT(deque)
	  if deque is empty
      error "underflow"
  x = deque[deque.head]
  if deque.head == deque.length
      deque.head = 1
  else
      deque.head = deque.head + 1
  return x



	PUSH-BACK(deque, x)
	  if deque is full
      error "overflow"
  deque[deque.tail] = x
  if deque.tail == deque.length
      deque.tail = 1
  else
      deque.tail = deque.tail + 1



POP-BACK(deque)
  if deque is empty
      error "underflow"
  if deque.tail == 1
      deque.tail = deque.length
  else
      deque.tail = deque.tail - 1
  x = deque[deque.tail]
  return x
