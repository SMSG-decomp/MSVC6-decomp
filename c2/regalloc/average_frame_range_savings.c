int __thiscall average_frame_range_savings(c2_bitset *ranges,int *total)

{
  uint8_t uVar1;
  c2_symbol *sym;
  uint32_t id;
  c2_live_range *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = 0;
  iVar5 = 0;
  iVar4 = 0;
  id = bitset_iter_next(ranges);
  while (id != 0xffffffff) {
    pcVar2 = live_range_from_id(id);
    sym = pcVar2->sym;
    iVar3 = load_saving(sym);
    iVar6 = iVar6 + iVar3;
    uVar1 = sym->cls;
    if ((((uVar1 == '\x03') || (uVar1 == '\x04')) || (uVar1 == '\x05')) || (uVar1 == '\x06')) {
      iVar5 = iVar5 + 1;
    }
    iVar4 = iVar4 + 1;
    id = bitset_iter_next((c2_bitset *)0x0);
  }
  *total = *total + iVar6 / iVar4;
  return iVar5;
}

