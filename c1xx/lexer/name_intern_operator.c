void * __cdecl name_intern_operator(uchar op)

{
  void *pvVar1;
  
  if (op == 'A') {
    pvVar1 = name_intern("[]");
    return pvVar1;
  }
  if (op != 'v') {
    pvVar1 = name_intern(g_token_spelling[op]);
    return pvVar1;
  }
  pvVar1 = name_intern("()");
  return pvVar1;
}

