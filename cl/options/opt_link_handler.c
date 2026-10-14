int __cdecl opt_link_handler(char **argv,int *index)

{
  char *name;
  optrec *rec;
  optrec *rec_2;
  char **word;
  int i;
  char **next;
  
  if (argv[*index][5] != '\0') {
    rec = optrec_new(argv[*index] + 5,(char *)0x0,"C",'\b');
    list_append(&g_driver_ctx_ptr->pass_options,rec);
  }
  i = *index + 1;
  word = argv + i;
  name = argv[i];
  while (name != (char *)0x0) {
    rec_2 = optrec_new(name,(char *)0x0,"C",'\b');
    list_append(&g_driver_ctx_ptr->pass_options,rec_2);
    next = word + 1;
    word = word + 1;
    i = i + 1;
    name = *next;
  }
  *index = i;
  return 0;
}

