c1_node * __thiscall conv_build_same_class(c1_conversion *conv,c1_node *dest)

{
  byte bVar1;
  c1_symbol *ctor;
  c1_node *pcVar2;
  c1_type *pcVar3;
  char register_dtor;
  bool bVar4;
  
  pcVar2 = conv->expr;
  bVar4 = g_ms_extensions == '\0';
  if (dest != (c1_node *)0x0) {
    ctor = (c1_symbol *)
           class_find_member_function_matching
                     (conv->source,(int)g_name_ctor,sym_is_copy_constructor);
    pcVar2 = expr_construct_result_in_place(ctor,dest,conv->expr);
    if (pcVar2 == (c1_node *)0x0) {
      pcVar2 = tree_append_list_item((c1_node *)0x0,conv->expr,2);
      if ((dest->type->code & 0x200) != 0) {
        pcVar3 = type_pointer_with_qualifiers(dest->type,0);
        dest->type = pcVar3;
      }
      if ((conv->target_symbol == (c1_symbol *)0x0) ||
         ((bVar1 = conv->target_symbol->storage & 7, 3 < bVar1 && (bVar1 < 7)))) {
        register_dtor = '\x01';
      }
      else {
        register_dtor = '\0';
      }
      pcVar2 = expr_build_call_of(ctor,(conv->target->extra).cls,dest,pcVar2,'\0',1,register_dtor);
      if (pcVar2 == (c1_node *)0x0) {
        return (c1_node *)0x0;
      }
      bVar4 = false;
    }
    pcVar2 = conv_register_target_destructor(conv,dest,pcVar2);
  }
  if (bVar4) {
    conv_check_nonlvalue_to_reference(conv,conv->source,'\0');
  }
  return pcVar2;
}

