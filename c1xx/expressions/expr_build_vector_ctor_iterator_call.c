c1_node * __cdecl
expr_build_vector_ctor_iterator_call(c1_node *array,int size,c1_node *count,int no_closure)

{
  char cVar1;
  c1_type *type;
  c1_type *pcVar2;
  c1_symbol *pcVar3;
  bool bVar4;
  c1_node *pcVar5;
  c1_node *item4;
  void *pvVar6;
  c1_node *left;
  c1_symbol *fn;
  uint uVar7;
  
  type = array->type;
  cVar1 = (char)type->code;
  pcVar2 = type;
  while (cVar1 < '\0') {
    pcVar2 = pcVar2->base;
    cVar1 = (char)pcVar2->code;
  }
  pcVar3 = (pcVar2->extra).cls;
  pcVar5 = expr_default_ctor_reference(type,(char)no_closure);
  if (((((pcVar3->detail).cls)->layout_flags3b & 0x10) != 0) && ((char)no_closure == '\0')) {
    fn = (c1_symbol *)class_find_default_constructor(type);
    uVar7 = func_takes_void_parameters(fn);
    if ((char)uVar7 != '\0') {
      bVar4 = true;
      goto LAB_1044c974;
    }
  }
  bVar4 = false;
LAB_1044c974:
  if ((g_opt_eh == '\0') || ((((pcVar3->detail).cls)->implicit_state41 & 0x10) != 0)) {
    pvVar6 = g_name_vector_vbase_ctor_iterator;
    if (!bVar4) {
      pvVar6 = g_name_vector_ctor_iterator;
    }
    left = expr_lookup_name_expression(pvVar6);
    item4 = (c1_node *)0x0;
  }
  else {
    item4 = expr_destructor_address(type);
    pvVar6 = g_name_eh_vector_vbase_ctor_iterator;
    if (!bVar4) {
      pvVar6 = g_name_eh_vector_ctor_iterator;
    }
    left = expr_lookup_name_expression(pvVar6);
  }
  pcVar5 = expr_build_helper_call_4(array,size,count,pcVar5,item4,left);
  return pcVar5;
}

