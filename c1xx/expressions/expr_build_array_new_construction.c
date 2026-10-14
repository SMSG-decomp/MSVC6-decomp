c1_node * __cdecl
expr_build_array_new_construction
          (c1_node *ptr,char may_be_null,int vptr,int cookie,c1_node *count,int elem_size)

{
  char cVar1;
  c1_type *pcVar2;
  int iVar3;
  c1_node *pcVar4;
  c1_node *array;
  c1_node *pcVar5;
  byte bVar6;
  c1_symbol *cls;
  int size;
  int no_closure;
  
  pcVar5 = count;
  iVar3 = cookie;
  if ((ptr != (c1_node *)0x0) && (count != (c1_node *)0x0)) {
    pcVar2 = ptr->type;
    cVar1 = (char)pcVar2->code;
    while (cVar1 < '\0') {
      pcVar2 = pcVar2->base;
      cVar1 = (char)pcVar2->code;
    }
    if ((pcVar2->code & 0x200) == 0) {
      cls = (c1_symbol *)0x0;
    }
    else {
      cls = (pcVar2->extra).cls;
    }
    if ((((cls->detail).cls)->implicit_state41 & 2) != 0) {
      if ((cls->flags2 & 4) == 0) {
        tmpl_instantiate_if_needed(cls);
      }
      bVar6 = ((cls->detail).cls)->implicit_state41 & 0x10;
      if (((bVar6 == 0) && ((((cls->detail).cls)->implicit_state43 & 0x10) == 0)) || (bVar6 != 0)) {
        if (may_be_null == '\0') {
          return ptr;
        }
        if (iVar3 == 0) {
          return ptr;
        }
      }
    }
    if (may_be_null != '\0') {
      expr_make_reusable(&count,&ptr);
    }
    if (iVar3 != 0) {
      type_size(g_type_unsigned_int);
      type_size(g_type_unsigned_long);
      pcVar4 = tree_copy_to_arena(ptr,0);
      pcVar5 = tree_new_binary_typed_right('4',pcVar4,pcVar5);
      pcVar4 = tree_new_unsigned_constant(iVar3);
      pcVar4->type = g_type_unsigned_int;
      ptr = tree_new_binary('Q',ptr,pcVar4);
    }
    pcVar4 = conv_convert_expression('d',g_type_int,pcVar5,'\x02','\0');
    iVar3 = elem_size;
    pcVar5 = ptr;
    if ((((cls->detail).cls)->implicit_state41 & 2) == 0) {
      size = elem_size;
      pcVar5 = pcVar4;
      no_closure = vptr;
      array = tree_copy_to_arena(ptr,0);
      pcVar5 = expr_build_vector_ctor_iterator_call(array,size,pcVar5,no_closure);
    }
    if (may_be_null != '\0') {
      if (pcVar5 != ptr) {
        pcVar4 = pcVar5;
      }
      ptr = tree_new_binary_typed_right('7',pcVar4,ptr);
      pcVar5 = expr_build_null_guarded(count,ptr);
      return pcVar5;
    }
    ptr = init_template_static_member(pcVar5,ptr,iVar3,pcVar4);
  }
  return ptr;
}

