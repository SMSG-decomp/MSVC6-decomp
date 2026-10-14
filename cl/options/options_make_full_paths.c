void __cdecl options_make_full_paths(void)

{
  char *full;
  char *p;
  char *p_2;
  int diff;
  char *p_3;
  char *p_4;
  cl_optrec *opt_2;
  cl_optrec *opt;
  
  g_enc = 1;
  full = xmalloc(0x400);
  for (opt_2 = g_driver_ctx_ptr->user_options; opt_2 != (cl_optrec *)0x0; opt_2 = opt_2->next) {
    if ((((opt_2->flags & 0x40) != 0) && ((opt_2->flags & 0x21) != 1)) &&
       (opt_2->value != (char *)0x0)) {
      p = path_full(full,opt_2->value,0x400);
      if (p != (char *)0x0) {
        xfree(opt_2->value);
        p_2 = xstrdup(full);
        opt_2->value = p_2;
      }
    }
  }
  for (opt = g_driver_ctx_ptr->pass_options; opt != (cl_optrec *)0x0; opt = opt->next) {
    diff = strcmp(opt->name,"I");
    if (diff == 0) {
      p_3 = path_full(full,opt->value,0x400);
      if (p_3 != (char *)0x0) {
        xfree(opt->value);
        p_4 = xstrdup(full);
        opt->value = p_4;
      }
    }
  }
  xfree(full);
  return;
}

