int __fastcall operand_live_after_loop(c2_operand *op)

{
  c2_symbol *pcVar1;
  c2_symbol *pcVar2;
  uint32_t uVar3;
  
  if ((1 << (op->kind & 0x1f) & 6U) != 0) {
    pcVar1 = op->sym;
    for (pcVar2 = pcVar1->storage; pcVar2 != (c2_symbol *)0x0; pcVar2 = pcVar2->part_next) {
      if (pcVar1 == pcVar2) {
LAB_107445f7:
        uVar3 = bitset_test(g_loop_live_out_syms,pcVar2->id);
        if (uVar3 != 0) {
          return 1;
        }
      }
      else if ((pcVar1->offset < pcVar2->size + pcVar2->offset) &&
              (pcVar2->offset < pcVar1->size + pcVar1->offset)) goto LAB_107445f7;
    }
  }
  return 0;
}

