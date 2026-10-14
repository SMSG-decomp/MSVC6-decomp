void __thiscall decl_append_function_layer(c1_type_declarator *declarator,int *params)

{
  int *piVar1;
  ushort uVar2;
  c1_type *layer;
  bool bVar3;
  
  piVar1 = params;
  bVar3 = declarator->first == (c1_type *)0x0;
  declarator->flags30 = declarator->flags30 | 0x10;
  decl_function_modifier_end_parameters(params);
  params = (int *)0x0;
  layer = (c1_type *)record_pos_new(0x81,0,(int *)&params);
  decl_function_modifier_check_parameters(layer,*piVar1,piVar1[1]);
  if ((bVar3) && (uVar2 = (ushort)declarator->modifiers & 7, uVar2 != 0)) {
    layer->flags = layer->flags | uVar2;
    *(ushort *)&declarator->modifiers = (ushort)declarator->modifiers & 0xfff8;
  }
  type_check_array_of_functions(declarator,layer);
  if (declarator->last == (c1_type *)0x0) {
    declarator->last = layer;
    declarator->first = layer;
  }
  else {
    declarator->last->base = layer;
    declarator->last = layer;
  }
  if (bVar3) {
    declarator->params = piVar1;
    declarator->flags30 = declarator->flags30 | 8;
  }
  return;
}

