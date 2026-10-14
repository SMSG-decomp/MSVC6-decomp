void __fastcall decl_check_declarator_type(c1_type_declarator *declarator)

{
  byte bVar1;
  c1_type *layer;
  
  bVar1 = (byte)declarator->base->code;
  if (-1 < (char)bVar1) {
    if (declarator->first != (c1_type *)0x0) {
      if (((bVar1 >> 6 & 1) != 0) && ((declarator->last->code & 0x8f) == 0x83)) {
        decl_check_declarator_void_fragment(declarator);
        return;
      }
      if ((((declarator->last->code & 0x8f) == 0x83) && ((declarator->base->code & 0x200) != 0)) &&
         ((((declarator->base->extra).sym)->flags4 & 1) != 0)) {
        diag_error(0xe9,declarator->sym);
        declarator->flags30 = declarator->flags30 | 1;
      }
      declarator->last->base = declarator->base;
    }
    return;
  }
  layer = type_descriptor_copy_transient(declarator->base);
  bVar1 = (byte)layer->code & 0x8f;
  if (bVar1 != 0x81) {
    if (bVar1 == 0x83) {
      type_build_array(declarator,layer);
      goto LAB_10604fb4;
    }
    if (bVar1 != 0x85) goto LAB_10604fb4;
  }
  type_check_array_of_functions(declarator,layer);
LAB_10604fb4:
  if (declarator->last == (c1_type *)0x0) {
    declarator->last = layer;
    declarator->first = layer;
    return;
  }
  declarator->last->base = layer;
  declarator->last = layer;
  return;
}

