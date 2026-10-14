c1_node * __cdecl
expr_build_vector_dtor_call(c1_node *array,int elem_size,c1_node *count,c1_type *type)

{
  void *name;
  c1_node *pcVar1;
  c1_node *item3;
  c1_node *item4;
  
  name = g_name_eh_vector_dtor_iterator;
  if (g_opt_eh == '\0') {
    name = g_name_vector_dtor_iterator;
  }
  pcVar1 = expr_lookup_name_expression(name);
  item4 = (c1_node *)0x0;
  item3 = expr_destructor_address(type);
  pcVar1 = expr_build_helper_call_4(array,elem_size,count,item3,item4,pcVar1);
  return pcVar1;
}

