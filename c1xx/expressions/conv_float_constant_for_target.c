c1xx_float_const * __thiscall
conv_float_constant_for_target(c1_conversion *conv,c1xx_float_const *value)

{
  c1xx_float_const *pcVar1;
  
  if (g_opt_Op != '\0') {
    fold_float_round_to_width
              ((int)value,(int)(char)(&g_type_rank_table)[(byte)conv->target->code & 0xf]);
  }
  value->size = (short)(char)(&g_type_rank_table)[(byte)conv->target->code & 0xf];
  pcVar1 = record3_new_from((int *)value,g_expr_arena_index);
  return pcVar1;
}

