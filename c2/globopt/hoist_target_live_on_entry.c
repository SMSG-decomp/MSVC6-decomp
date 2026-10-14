uint32_t __fastcall hoist_target_live_on_entry(c2_symbol *sym,c2_bitset *bs,c2_bitset *bs2)

{
  c2_symbol *pcVar1;
  uint32_t uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  c2_symbol *pcVar6;
  
  uVar2 = bitset_test(bs,sym->id);
  if (uVar2 != 0) {
    return 1;
  }
  pcVar1 = sym->storage;
  pcVar6 = pcVar1;
  do {
    if (pcVar6 == (c2_symbol *)0x0) {
      return 0;
    }
    if (pcVar6 != sym) {
      if (((pcVar6->offset < sym->size + sym->offset) &&
          (sym->offset < pcVar6->size + pcVar6->offset)) &&
         (uVar2 = bitset_test(bs,pcVar6->id), uVar2 != 0)) {
        if (pcVar6 == (c2_symbol *)0x0) {
          return 0;
        }
        if (pcVar1->size < 0x101) {
          uVar5 = 0xffffffff;
          pcVar6 = pcVar1;
          do {
            uVar2 = bitset_test(bs2,pcVar6->id);
            if (uVar2 != 0) {
              iVar4 = pcVar6->offset;
              iVar3 = pcVar6->size + -1 + iVar4;
              for (iVar4 = (int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3;
                  iVar4 <= (int)(iVar3 + (iVar3 >> 0x1f & 7U)) >> 3; iVar4 = iVar4 + 1) {
                uVar5 = uVar5 & ~(1 << ((byte)iVar4 & 0x1f));
              }
            }
            pcVar6 = pcVar6->part_next;
          } while (pcVar6 != (c2_symbol *)0x0);
          iVar3 = pcVar1->size + 7;
          if ((uVar5 & (1 << ((byte)((int)(iVar3 + (iVar3 >> 0x1f & 7U)) >> 3) & 0x1f)) - 1U) == 0)
          {
            return 0;
          }
          return 1;
        }
        return 1;
      }
    }
    pcVar6 = pcVar6->part_next;
  } while( true );
}

