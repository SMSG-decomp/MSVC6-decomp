int __fastcall symbol_contains(c2_symbol *a,c2_symbol *b)

{
  uint8_t uVar1;
  uint8_t uVar2;
  c2_symbol *pcVar3;
  c2_symbol *pcVar4;
  int iVar5;
  c2_symbol *pcVar6;
  int iVar7;
  
  pcVar3 = b->storage;
  pcVar4 = a->storage;
  if (pcVar4 == pcVar3) {
    if ((a->offset <= b->offset) && (b->size + b->offset <= a->size + a->offset)) {
      return 1;
    }
  }
  else if (((g_frame_offsets_assigned != 0) &&
           ((((uVar1 = a->cls, uVar1 == '\x03' || (uVar1 == '\x04')) || (uVar1 == '\x05')) ||
            (uVar1 == '\x06')))) &&
          ((((uVar2 = b->cls, uVar2 == '\x03' || (uVar2 == '\x04')) || (uVar2 == '\x05')) ||
           (uVar2 == '\x06')))) {
    if (uVar1 == '\x03') {
      pcVar6 = (pcVar4->u28).free_next;
    }
    else {
      pcVar6 = (c2_symbol *)pcVar4->fe->offset;
    }
    iVar7 = (int)pcVar6 + (a->offset - pcVar4->offset);
    if (uVar2 == '\x03') {
      pcVar4 = (pcVar3->u28).free_next;
    }
    else {
      pcVar4 = (c2_symbol *)pcVar3->fe->offset;
    }
    iVar5 = (int)pcVar4 + (b->offset - pcVar3->offset);
    if ((iVar7 <= iVar5) && (b->size + iVar5 <= a->size + iVar7)) {
      return 1;
    }
  }
  return 0;
}

