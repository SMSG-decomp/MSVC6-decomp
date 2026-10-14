void __cdecl srcfile_append(char *name,int type,short explicit_type)

{
  srcfile *f;
  cl_srcfile *last;
  cl_srcfile *next;
  cl_srcfile *next_2;
  
  f = srcfile_new(name,type);
  f->explicit_type = explicit_type;
  next_2 = (cl_srcfile *)&g_driver_ctx_ptr->files;
  do {
    last = next_2;
    next_2 = last->next;
  } while (last->next != (cl_srcfile *)0x0);
  last->next = f;
  if (g_file_types[type].kind == 0) {
    g_compilable_files = g_compilable_files + 1;
  }
  return;
}

