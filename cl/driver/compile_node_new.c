node * __cdecl compile_node_new(srcfile *f)

{
  node *n;
  
  n = xmalloc(0x28);
  n->next = (cl_compile_node *)0x0;
  n->failed = 0;
  n->file = f;
  return n;
}

