int __fastcall operands_may_alias_case_1(c2_operand *a,c2_operand *b)

{
  uint8_t uVar1;
  uint8_t uVar2;
  c2_symbol *pcVar3;
  c2_symbol *pcVar4;
  c2_symbol *pcVar5;
  c2_symbol *pcVar6;
  int iVar7;
  c2_symbol *pcVar8;
  int iVar9;
  
  if (((b->u18).reg)->cls != '\x02') {
    return 0;
  }
  pcVar3 = b->sym;
  pcVar4 = a->sym;
  pcVar5 = pcVar3->storage;
  pcVar6 = pcVar4->storage;
  if (pcVar6 != pcVar5) {
    if (((g_frame_offsets_assigned != 0) &&
        ((((uVar1 = pcVar4->cls, uVar1 == '\x03' || (uVar1 == '\x04')) || (uVar1 == '\x05')) ||
         (uVar1 == '\x06')))) &&
       ((((uVar2 = pcVar3->cls, uVar2 == '\x03' || (uVar2 == '\x04')) || (uVar2 == '\x05')) ||
        (uVar2 == '\x06')))) {
      if (uVar1 == '\x03') {
        pcVar8 = (pcVar6->u28).free_next;
      }
      else {
        pcVar8 = (c2_symbol *)pcVar6->fe->offset;
      }
      iVar9 = (int)pcVar8 + (pcVar4->offset - pcVar6->offset);
      if (uVar2 == '\x03') {
        pcVar6 = (pcVar5->u28).free_next;
      }
      else {
        pcVar6 = (c2_symbol *)pcVar5->fe->offset;
      }
      iVar7 = (int)pcVar6 + (pcVar3->offset - pcVar5->offset);
      if ((iVar9 < pcVar3->size + iVar7) && (iVar7 < pcVar4->size + iVar9)) {
        return 1;
      }
    }
    return 0;
  }
  if (pcVar4 != pcVar3) {
    if (pcVar3->size + pcVar3->offset <= pcVar4->offset) {
      return 0;
    }
    if (pcVar4->size + pcVar4->offset <= pcVar3->offset) {
      return 0;
    }
  }
  return 1;
}

