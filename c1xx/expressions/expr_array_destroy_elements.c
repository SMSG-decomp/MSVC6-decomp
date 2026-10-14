c1_node * __cdecl expr_array_destroy_elements(c1_node *array)

{
  c1_type *pcVar1;
  c1_u32 cVar2;
  int elem_size;
  c1_node *pcVar3;
  int iVar4;
  c1_type *pcVar5;
  
  iVar4 = 1;
  pcVar5 = array->type;
  while (pcVar1 = pcVar5->base, (pcVar1->code & 0x8f) == 0x83) {
    pcVar3 = tree_new_int_constant(0);
    array = expr_build_binary('A',array,pcVar3);
    iVar4 = iVar4 * (pcVar5->extra).count;
    pcVar5 = pcVar1;
  }
  cVar2 = (pcVar5->extra).count;
  pcVar5 = array->type->base;
  elem_size = type_size_derived(pcVar5);
  pcVar3 = tree_new_int_constant(cVar2 * iVar4);
  pcVar3 = expr_build_vector_dtor_call(array,elem_size,pcVar3,pcVar5);
  return pcVar3;
}

