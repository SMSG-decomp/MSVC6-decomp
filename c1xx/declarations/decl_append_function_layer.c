void __thiscall decl_append_function_layer(int *rec,void *params)

{
  int iVar1;
  void *params_00;
  c1_type *fn;
  c1_node *pcVar2;
  c1_type *pcVar3;
  char chain_was_empty;
  
  params_00 = params;
  iVar1 = rec[1];
  *(byte *)(rec + 0xf) = *(byte *)(rec + 0xf) | 0x10;
  chain_was_empty = iVar1 == 0;
  decl_pop_declarator_state(params);
  params = (void *)0x0;
  fn = (c1_type *)record_pos_new(0x81,0,(int *)&params);
  if (iVar1 == 0) {
    if ((*(ushort *)(rec + 3) & 7) != 0) {
      fn->flags = fn->flags | *(ushort *)(rec + 3) & 7;
      *(ushort *)(rec + 3) = *(ushort *)(rec + 3) & 0xfff8;
    }
  }
  else if ((*(byte *)rec[2] & 0x8f) == 0x8a) {
    pcVar3 = type_this_pointer(*(c1_symbol **)((byte *)rec[2] + 8),0x20,
                               *(ushort *)((int)params_00 + 4));
    iVar1 = *(int *)params_00;
    pcVar2 = decl_chain_default_arguments(*(c1_arg_list **)((int)params_00 + 0xc));
    decl_set_parameter_type(fn,iVar1,pcVar2,pcVar3);
    *(byte *)&fn->code = (byte)fn->code | 0x85;
  }
  else {
    iVar1 = *(int *)params_00;
    pcVar3 = (c1_type *)0x0;
    pcVar2 = decl_chain_default_arguments(*(c1_arg_list **)((int)params_00 + 0xc));
    decl_set_parameter_type(fn,iVar1,pcVar2,pcVar3);
    if (*(short *)((int)params_00 + 4) != 0) {
      decl_append_function_layer_modifiers_fragment(rec,fn,params_00,chain_was_empty);
      return;
    }
  }
  decl_append_derived_check((c1_decl_record *)rec,fn);
  if (rec[2] == 0) {
    rec[2] = (int)fn;
    rec[1] = (int)fn;
  }
  else {
    *(c1_type **)(rec[2] + 4) = fn;
    rec[2] = (int)fn;
  }
  if (chain_was_empty != '\0') {
    rec[6] = (int)params_00;
    *(byte *)(rec + 0xf) = *(byte *)(rec + 0xf) | 8;
  }
  return;
}

