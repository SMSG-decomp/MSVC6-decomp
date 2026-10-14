void __cdecl srcfiles_make_full_paths(void)

{
  char *full;
  char *p;
  char *p_2;
  cl_srcfile *f;
  
  full = xmalloc(0x400);
  for (f = g_driver_ctx_ptr->files; f != (cl_srcfile *)0x0; f = f->next) {
    if (g_file_types[f->type].kind == 0) {
      p = path_full(full,f->name,0x400);
      if (p != (char *)0x0) {
        p_2 = xstrdup(full);
        f->fullname = p_2;
      }
    }
  }
  xfree(full);
  return;
}

