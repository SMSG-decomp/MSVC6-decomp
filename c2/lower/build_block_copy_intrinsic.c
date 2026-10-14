c2_tuple * __fastcall
build_block_copy_intrinsic
          (c2_operand *dst,c2_node *a,c2_node *b,c2_operand *c,c2_tuple *anchor,uint32_t alias,
          uint32_t alias2,c2_insert_fn *insert_fn)

{
  c2_tuple *pcVar1;
  c2_operand *pcVar2;
  
  pcVar1 = tuple_new_intrinsic(400,0x5000,dst,(c2_operand *)a,(c2_operand *)b,c,(c2_operand *)0x0,
                               0xac,insert_fn,anchor);
  wrap_first_args_in_arg_copies(pcVar1,3);
  bind_intrinsic_operand_registers(pcVar1);
  if (g_opt_global != 0) {
    pcVar2 = operand_new_memeffect(alias);
    tuple_append_dst(pcVar1,pcVar2);
    pcVar2 = operand_new_memeffect(alias2);
    tuple_append_src(pcVar1,pcVar2);
  }
  pcVar1 = lower_intrinsic(pcVar1);
  return pcVar1;
}

