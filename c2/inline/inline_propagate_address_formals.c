void __fastcall inline_propagate_address_formals(c2_tuple *entry)

{
  uint8_t *puVar1;
  uint32_t *puVar2;
  uint8_t uVar3;
  c2_tuple *t;
  c2_symbol *pcVar4;
  c2_fe_symbol *pcVar5;
  c2_operand *pcVar6;
  c2_operand *addr_value;
  c2_operand *pcVar7;
  uint32_t op;
  c2_replace_fn *replace_fn;
  c2_operand *found_list;
  c2_operand *next_sub;
  
  for (t = entry->next; t != (c2_tuple *)0x0; t = t->next) {
    if ((t->flags & 1) != 0) {
      if (t->op == 0x1a0) {
        inline_propagate_address_formals(((t->u20).eh_construct)->object->funclet->cfg->first->head)
        ;
      }
      else if (t->op == 0x1ab) {
        inline_propagate_address_formals((t->u20).default_label);
      }
      else {
        pcVar6 = t->src;
        while (pcVar7 = pcVar6, pcVar7 != (c2_operand *)0x0) {
          pcVar6 = pcVar7->next;
          next_sub = pcVar6;
          if (((pcVar7->kind == '\x02') && (pcVar7->sym->cls == '\x05')) &&
             (addr_value = (c2_operand *)pcVar7->sym->storage->order_next,
             addr_value != (c2_operand *)0x0)) {
            if (addr_value->kind == '\x03') {
              pcVar4 = addr_value->sym->storage;
              pcVar5 = addr_value->sym->fe;
              puVar1 = &pcVar4->flags5;
              *puVar1 = *puVar1 | 0x80;
              if ((pcVar5 != (c2_fe_symbol *)0x0) && ((pcVar5->storage & 0x40000) != 0)) {
                puVar2 = &pcVar4->fe->storage;
                *puVar2 = *puVar2 & 0xfffbffff;
              }
            }
            if ((pcVar7->flags & 0x20) == 0) {
              tuple_replace_src(t,pcVar7,addr_value);
            }
            else {
              pcVar6 = find_mem_operand_using(t,pcVar7,&found_list);
              uVar3 = addr_value->sym->cls;
              if (((uVar3 == '\x03') || (uVar3 == '\x04')) ||
                 ((uVar3 == '\x05' || (op = 0x14b, uVar3 == '\x06')))) {
                op = 0x14a;
              }
              replace_fn = tuple_replace_dst;
              if (found_list != t->dst) {
                replace_fn = tuple_replace_src;
              }
              addr_value = (c2_operand *)
                           symbol_get_part(addr_value->sym,pcVar6->type,pcVar6->type & 0xfff,0);
              pcVar7 = operand_new_sym(op,pcVar6->type,(c2_symbol *)addr_value);
              (*replace_fn)(t,pcVar6,pcVar7);
              pcVar6 = next_sub;
            }
          }
        }
      }
    }
  }
  return;
}

