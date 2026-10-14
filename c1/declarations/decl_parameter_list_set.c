void __thiscall decl_parameter_list_set(int *list,int first,int unused)

{
  *list = first;
  list[1] = 0;
  return;
}

