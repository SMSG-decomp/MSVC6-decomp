void __thiscall decl_append_array_layer(c1_decl_record *rec,int *bound)

{
  c1_type *layer;
  
  bound = (int *)*bound;
  if ((int)bound < 0) {
    diag_error(0x76);
    bound = (int *)0x1;
  }
  layer = (c1_type *)record_pos_new(0x83,0,(int *)&bound);
  type_check_array_declarator(rec,layer);
  if (rec->chain_tail == (c1_type *)0x0) {
    rec->chain_tail = layer;
    rec->chain_head = layer;
    return;
  }
  rec->chain_tail->base = layer;
  rec->chain_tail = layer;
  return;
}

