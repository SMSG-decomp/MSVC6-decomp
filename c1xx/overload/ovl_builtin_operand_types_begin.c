void __thiscall
ovl_builtin_operand_types_begin
          (c1_builtin_operand_iter *iter,c1_node *node,c1_type *pattern,uint need_lvalue)

{
  c1_type *pcVar1;
  byte bVar2;
  c1_u8 cVar3;
  c1_symbol *cls;
  
  iter->operand = node;
  iter->pattern = pattern;
  pcVar1 = node->type;
  if ((pcVar1->code & 0x200) == 0) {
    bVar2 = (byte)pcVar1->code;
    if ((((char)bVar2 < '\0') && ((bVar2 & 0x8f) == 0x80)) && ((pcVar1->base->code & 0x200) != 0)) {
      cls = (pcVar1->base->extra).cls;
      cVar3 = '\x01';
    }
    else {
      cVar3 = '\0';
      cls = (c1_symbol *)need_lvalue;
    }
  }
  else {
    cVar3 = '\x01';
    cls = (pcVar1->extra).cls;
  }
  iter->via_class = cVar3;
  iter->need_lvalue = (c1_u8)need_lvalue;
  if (cVar3 != '\0') {
    class_conversion_functions_begin(&iter->conversions,cls);
  }
  return;
}

