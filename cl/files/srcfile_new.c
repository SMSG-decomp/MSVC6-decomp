srcfile * __cdecl srcfile_new(char *name,int type)

{
  srcfile *f;
  char *copy;
  
  f = xmalloc(0x14);
  f->type = type;
  f->explicit_type = 1;
  copy = xstrdup(name);
  f->next = (cl_srcfile *)0x0;
  f->batch_index = -1;
  f->fullname = copy;
  f->name = copy;
  return f;
}

