optrec * __cdecl optrec_new(char *name,char *value,char *passes,uint8_t flags)

{
  cl_optrec *r;
  char *copy;
  char *copy_2;
  char *copy_3;
  
  if (g_optrec_free_list == (cl_optrec *)0x0) {
    r = xmalloc(0x18);
  }
  else {
    r = g_optrec_free_list;
    g_optrec_free_list = g_optrec_free_list->next;
  }
  memset(r,0,0x18);
  r->flags = flags;
  copy = xstrdup(value);
  r->value = copy;
  copy_2 = xstrdup(name);
  r->name = copy_2;
  copy_3 = xstrdup(passes);
  r->passes = copy_3;
  return r;
}

