void __cdecl drv_bp_set_pass_path(optrec *r)

{
  char *path;
  cl_pass *pass;
  char which;
  
  pass = g_passes;
  which = *r->value;
  do {
    if ((which == '.') || (pass->letter == which)) {
      path = xstrdup(r->value + 1);
      pass->program = path;
    }
    pass = pass + 1;
  } while ((int)pass < 0x40b1c4);
  return;
}

