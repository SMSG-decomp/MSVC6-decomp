c2_tuple * __fastcall lower_tuple(c2_tuple *t)

{
  uint uVar1;
  uint32_t uVar2;
  c2_tuple *pcVar3;
  c2_tuple *pcVar4;
  
  pcVar3 = t->next;
  if ((t->flags & 1) == 0) {
    return pcVar3;
  }
  if (((t->type & 0xf000) == 0x4000) ||
     ((((uVar1 = t->op, uVar1 != 0 && (uVar1 < 0x144)) && ((g_x86_op_flags[uVar1] & 1) != 0)) ||
      ((t->src != (c2_operand *)0x0 && ((t->src->type & 0xf000) == 0x4000)))))) {
    tuple_legalize_mem_operands(t);
    pcVar3 = lower_x87_tuple(t);
    if (((1 << (byte)(pcVar3->type >> 0xc) & 0xeU) != 0) &&
       (((uVar2 = pcVar3->op, pcVar4 = pcVar3, uVar2 == 0x15b || (uVar2 == 0x17d)) ||
        (uVar2 == 0x15a)))) goto LAB_1071b4fb;
  }
  else {
    if (uVar1 == 0x178) {
      lower_flag_test_copy(t);
      return pcVar3;
    }
    pcVar3 = (c2_tuple *)lower_int_tuple(t);
    tuple_legalize_mem_operands(pcVar3);
    pcVar3 = legalize_machine_tuple(pcVar3);
  }
  pcVar4 = pcVar3->next;
LAB_1071b4fb:
  if (pcVar3->op == 0x145) {
    tuple_unlink_free(pcVar3);
  }
  return pcVar4;
}

