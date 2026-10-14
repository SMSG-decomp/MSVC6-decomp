void __thiscall
decl_append_function_layer_modifiers_fragment
          (int *rec,c1_type *fn_layer,void *params,char chain_was_empty)

{
  diag_error(0x10e,rec[0xd]);
  *(byte *)(rec + 0xf) = *(byte *)(rec + 0xf) | 1;
  decl_append_derived_check((c1_decl_record *)rec,fn_layer);
  if (rec[2] == 0) {
    rec[2] = (int)fn_layer;
    rec[1] = (int)fn_layer;
  }
  else {
    *(c1_type **)(rec[2] + 4) = fn_layer;
    rec[2] = (int)fn_layer;
  }
  if (chain_was_empty != '\0') {
    rec[6] = (int)params;
    *(byte *)(rec + 0xf) = *(byte *)(rec + 0xf) | 8;
  }
  return;
}

