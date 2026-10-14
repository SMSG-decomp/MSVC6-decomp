void __fastcall link_expression_operands(c2_symbol *s)

{
  c2_operand *pcVar1;
  c2_copy_link *pcVar2;
  c2_symbol_u38 cVar3;
  uint uVar4;
  c2_copy_link *pcVar5;
  c2_bitset *pcVar6;
  c2_symbol *src_sym;
  
  pcVar1 = ((s->u18).expr)->operands;
  do {
    if (pcVar1 == (c2_operand *)0x0) {
      return;
    }
    uVar4 = 1 << (pcVar1->kind & 0x1f);
    if ((uVar4 & 6) == 0) {
      if ((uVar4 & 0x60) != 0) {
        src_sym = (c2_symbol *)(pcVar1->u18).range;
        pcVar2 = (src_sym->u34).source_links;
        for (pcVar5 = pcVar2; pcVar5 != (c2_copy_link *)0x0; pcVar5 = pcVar5->next_of_source) {
          if (pcVar5->copy == s) goto LAB_1070ddb7;
        }
        pcVar5 = arena_alloc(0xd,0x10);
        cVar3 = s->u38;
        pcVar5->copy = s;
        pcVar5->next_of_source = pcVar2;
        (src_sym->u34).source_links = pcVar5;
        pcVar5->source = src_sym;
        pcVar5->next_of_copy = (c2_copy_link *)cVar3;
        (s->u38).copy_links = pcVar5;
        if (s->dependents == (c2_bitset *)0x0) {
          pcVar6 = bitset_new(0xd);
          s->dependents = pcVar6;
          bitset_set(pcVar6,s->id);
        }
        pcVar6 = src_sym->dependents;
        goto joined_r0x1070de20;
      }
    }
    else {
      src_sym = pcVar1->sym;
      pcVar2 = (src_sym->u34).source_links;
      for (pcVar5 = pcVar2; pcVar5 != (c2_copy_link *)0x0; pcVar5 = pcVar5->next_of_source) {
        if (pcVar5->copy == s) goto LAB_1070ddb7;
      }
      pcVar5 = arena_alloc(0xd,0x10);
      cVar3 = s->u38;
      pcVar5->copy = s;
      pcVar5->next_of_source = pcVar2;
      (src_sym->u34).source_links = pcVar5;
      pcVar5->source = src_sym;
      pcVar5->next_of_copy = (c2_copy_link *)cVar3;
      (s->u38).copy_links = pcVar5;
      if (s->dependents == (c2_bitset *)0x0) {
        pcVar6 = bitset_new(0xd);
        s->dependents = pcVar6;
        bitset_set(pcVar6,s->id);
      }
      pcVar6 = src_sym->dependents;
joined_r0x1070de20:
      if (pcVar6 == (c2_bitset *)0x0) {
        pcVar6 = bitset_new(0xd);
        src_sym->dependents = pcVar6;
        bitset_set(pcVar6,src_sym->id);
      }
      propagate_kill_sets(s);
    }
LAB_1070ddb7:
    pcVar1 = pcVar1->next;
  } while( true );
}

