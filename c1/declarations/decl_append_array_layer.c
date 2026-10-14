void __thiscall decl_append_array_layer(c1_type_declarator *declarator,int *bound)

{
  c1_type *layer;
  
  bound = (int *)*bound;
  if ((int)bound < 0) {
    diag_error(0x76);
    bound = (int *)0x1;
  }
  layer = (c1_type *)record_pos_new(0x83,0,(int *)&bound);
  type_build_array(declarator,layer);
  if (declarator->last == (c1_type *)0x0) {
    declarator->last = layer;
    declarator->first = layer;
    return;
  }
  declarator->last->base = layer;
  declarator->last = layer;
  return;
}

