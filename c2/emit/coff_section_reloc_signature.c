uint32_t __fastcall coff_section_reloc_signature(c2_coff_section_out *sec,uint32_t sig)

{
  char cVar1;
  c2_coff_reloc_chunk *pcVar2;
  uint32_t step_sig;
  c2_coff_reloc_chunk *pcVar3;
  uint uVar4;
  uint32_t uVar5;
  uint16_t *puVar6;
  char *pcVar7;
  c2_coff_symbol *target;
  
  pcVar2 = sec->relocs;
  pcVar3 = pcVar2;
  do {
    pcVar3 = pcVar3->last;
    uVar5 = pcVar3->count;
    if (uVar5 != 0) {
      puVar6 = &pcVar3->relocs[uVar5 - 1].type;
      do {
        target = g_coff_symbol_slots[*(uint32_t *)(puVar6 + -2)]->payload;
        if (*(int *)target->short_name == 0) {
          uVar4 = 0xffffffff;
          pcVar7 = *(char **)(target->short_name + 4);
          do {
            if (uVar4 == 0) break;
            uVar4 = uVar4 - 1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          step_sig = SigForPbCb(*(char **)(target->short_name + 4),~uVar4 - 1,sig);
        }
        else {
          step_sig = SigForPbCb(target,8,sig);
        }
        step_sig = SigForPbCb((c2_coff_reloc *)(puVar6 + -4),4,step_sig);
        sig = SigForPbCb(puVar6,2,step_sig);
        uVar5 = uVar5 - 1;
        puVar6 = puVar6 + -5;
      } while (uVar5 != 0);
    }
    if (pcVar3 == pcVar2) {
      return sig;
    }
  } while( true );
}

