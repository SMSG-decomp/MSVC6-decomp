void __cdecl option_conflict_message(int msg,optrec *a,optrec *b)

{
  char *a_value;
  char *b_value;
  cl_message_fn report;
  
  b_value = "";
  if (b->value != (char *)0x0) {
    b_value = b->value;
  }
  a_value = a->value;
  if (a_value == (char *)0x0) {
    a_value = "";
  }
  report = cl_warning;
  if (msg < 4000) {
    report = cl_error;
  }
  (*report)(msg,a->name,a_value,b->name,b_value);
  return;
}

