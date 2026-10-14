c1_node * __thiscall conv_store_converted_value(c1_conversion *conv,c1_node *dest,c1_node *value)

{
  c1_symbol *cls;
  byte bVar1;
  c1_node *pcVar2;
  char emit;
  int dtor_kind;
  char register_dtor;
  
  if (conv->target_class != 6) {
    pcVar2 = tree_new_node('4',dest,value,conv->target);
    return pcVar2;
  }
  if ((conv->target_symbol == (c1_symbol *)0x0) ||
     ((bVar1 = conv->target_symbol->storage & 7, 3 < bVar1 && (bVar1 < 7)))) {
    register_dtor = '\x01';
  }
  else {
    register_dtor = '\0';
  }
  cls = (conv->target->extra).cls;
  dtor_kind = 1;
  emit = '\0';
  pcVar2 = tree_append_list_item((c1_node *)0x0,value,2);
  pcVar2 = expr_build_call_of((c1_symbol *)0x0,cls,dest,pcVar2,emit,dtor_kind,register_dtor);
  return pcVar2;
}

