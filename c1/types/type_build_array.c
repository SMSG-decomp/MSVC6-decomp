void __thiscall type_build_array(c1_type_declarator *declarator,c1_type *layer)

{
  if (declarator->first != (c1_type *)0x0) {
    if (((layer->extra).sym == (c1_symbol *)0x0) && ((declarator->last->code & 0x8f) == 0x83)) {
      diag_error(0x57,declarator->sym);
      declarator->flags30 = declarator->flags30 | 1;
      (layer->extra).count = 1;
    }
    if ((declarator->last->code & 0x83) == 0x81) {
      diag_error(0x5a,declarator->sym);
      declarator->flags30 = declarator->flags30 | 1;
      layer->code = 0x82;
      (layer->extra).sym = (c1_symbol *)0x0;
    }
  }
  return;
}

