void __fastcall mark_operand_register_candidate(c2_operand *opnd)

{
  if ((g_opt_global != 0) && (((opnd->type & 0xf000) != 0x4000 || (g_opt_float_consistency == 0))))
  {
    opnd->kind = '\x01';
    opnd->op = 0x149;
    (opnd->u18).reg = &g_register_candidate_home;
    return;
  }
  return;
}

