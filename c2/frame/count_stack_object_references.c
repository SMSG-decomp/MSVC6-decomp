void __fastcall count_stack_object_references(c2_function *fn)

{
  uint8_t uVar1;
  c2_block *pcVar2;
  c2_tuple *pcVar3;
  c2_tuple *pcVar4;
  c2_operand *pcVar5;
  c2_symbol_cell *pcVar6;
  c2_symbol *member;
  c2_symbol_cell *member_cell;
  c2_symbol_cell *pcVar7;
  
  pcVar2 = fn->cfg->first;
  do {
    if (pcVar2 == (c2_block *)0x0) {
      return;
    }
    pcVar4 = pcVar2->end;
    for (pcVar3 = pcVar2->head; pcVar3 != pcVar4; pcVar3 = pcVar3->next) {
      if ((pcVar3->flags & 1) != 0) {
        for (pcVar5 = pcVar3->src; pcVar5 != (c2_operand *)0x0; pcVar5 = pcVar5->next) {
          switch(pcVar5->kind) {
          case '\x02':
          case '\x03':
            member = pcVar5->sym->storage;
            uVar1 = member->cls;
joined_r0x10734b77:
            if (((uVar1 == '\x03') || (uVar1 == '\x04')) || (uVar1 == '\x05')) {
              order_stack_object(member,1);
            }
            break;
          case '\x05':
          case '\x06':
            if ((pcVar5->base_sym != (c2_symbol *)0x0) &&
               (member = pcVar5->base_sym->storage, member != (c2_symbol *)0x0)) {
              uVar1 = member->cls;
              goto joined_r0x10734b77;
            }
            break;
          case '\v':
            if (pcVar3->kind == '\x15') {
              pcVar6 = alias_class_members((uint32_t)pcVar5->sym);
              pcVar7 = (c2_symbol_cell *)0x0;
joined_r0x107939a2:
              if (pcVar6 != (c2_symbol_cell *)0x0) {
                do {
                  member = pcVar6->sym;
                  member_cell = pcVar6;
                  if (member->cls == '\f') {
                    member_cell = (member->u30).members;
                    pcVar7 = pcVar6;
                    if (member_cell == (c2_symbol_cell *)0x0) {
                      pcVar6 = pcVar6->next;
                      goto joined_r0x107939a2;
                    }
                    member = member_cell->sym;
                  }
                  uVar1 = member->storage->cls;
                  if (((uVar1 == '\x03') || (uVar1 == '\x04')) || (uVar1 == '\x05')) {
                    order_stack_object(member->storage,1);
                  }
                  pcVar6 = member_cell->next;
                } while (pcVar6 != (c2_symbol_cell *)0x0);
                if (pcVar7 == (c2_symbol_cell *)0x0) break;
                pcVar6 = pcVar7->next;
                pcVar7 = (c2_symbol_cell *)0x0;
                goto joined_r0x107939a2;
              }
            }
          }
        }
        for (pcVar5 = pcVar3->dst; pcVar5 != (c2_operand *)0x0; pcVar5 = pcVar5->next) {
          switch(pcVar5->kind) {
          case '\x02':
          case '\x03':
            member = pcVar5->sym->storage;
            uVar1 = member->cls;
joined_r0x10734c19:
            if (((uVar1 == '\x03') || (uVar1 == '\x04')) || (uVar1 == '\x05')) {
              order_stack_object(member,1);
            }
            break;
          case '\x05':
          case '\x06':
            if ((pcVar5->base_sym != (c2_symbol *)0x0) &&
               (member = pcVar5->base_sym->storage, member != (c2_symbol *)0x0)) {
              uVar1 = member->cls;
              goto joined_r0x10734c19;
            }
            break;
          case '\v':
            if (pcVar3->kind == '\x15') {
              pcVar6 = alias_class_members((uint32_t)pcVar5->sym);
              pcVar7 = (c2_symbol_cell *)0x0;
joined_r0x10793a0c:
              if (pcVar6 != (c2_symbol_cell *)0x0) {
                do {
                  member = pcVar6->sym;
                  member_cell = pcVar6;
                  if (member->cls == '\f') {
                    member_cell = (member->u30).members;
                    pcVar7 = pcVar6;
                    if (member_cell == (c2_symbol_cell *)0x0) {
                      pcVar6 = pcVar6->next;
                      goto joined_r0x10793a0c;
                    }
                    member = member_cell->sym;
                  }
                  uVar1 = member->storage->cls;
                  if (((uVar1 == '\x03') || (uVar1 == '\x04')) || (uVar1 == '\x05')) {
                    order_stack_object(member->storage,1);
                  }
                  pcVar6 = member_cell->next;
                } while (pcVar6 != (c2_symbol_cell *)0x0);
                if (pcVar7 == (c2_symbol_cell *)0x0) break;
                pcVar6 = pcVar7->next;
                pcVar7 = (c2_symbol_cell *)0x0;
                goto joined_r0x10793a0c;
              }
            }
          }
        }
      }
    }
    pcVar2 = pcVar2->next;
  } while( true );
}

