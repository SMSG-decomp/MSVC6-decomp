int __fastcall symbol_in_alias_class(c2_symbol *sym,uint32_t alias_class)

{
  c2_symbol_cell *pcVar1;
  c2_symbol_cell *group_cell;
  c2_symbol *member;
  c2_symbol *storage;
  
  if (alias_class == 1) {
    return 1;
  }
  storage = sym->storage;
  if (g_alias_class_count <= alias_class) {
    alias_class = g_alias_secondary_records[alias_class - g_alias_class_count].parent;
  }
  switch(storage->cls) {
  case '\x04':
  case '\x05':
    if ((storage->flags5 & 2) != 0) {
      if ((storage->flags5 & 4) == 0) {
        if ((g_alias_pointee_class_base <= alias_class) &&
           (pcVar1 = g_alias_primary_table[alias_class], pcVar1 != (c2_symbol_cell *)0x0)) {
          do {
            if (pcVar1->sym == storage) {
              return 1;
            }
            pcVar1 = pcVar1->next;
          } while (pcVar1 != (c2_symbol_cell *)0x0);
          return 0;
        }
      }
      else {
        pcVar1 = g_alias_primary_table[alias_class];
        if (pcVar1 != (c2_symbol_cell *)0x0) {
          do {
            member = pcVar1->sym;
            if (member->cls == '\f') {
              for (group_cell = (member->u30).members; group_cell != (c2_symbol_cell *)0x0;
                  group_cell = group_cell->next) {
                if (group_cell->sym == storage) {
                  return 1;
                }
              }
            }
            else if (member == storage) {
              return 1;
            }
            pcVar1 = pcVar1->next;
          } while (pcVar1 != (c2_symbol_cell *)0x0);
          return 0;
        }
      }
    }
    break;
  case '\a':
  case '\b':
    if (((storage->flags5 & 4) == 0) || ((storage->flags5 & 2) != 0)) {
      for (pcVar1 = g_alias_primary_table[alias_class]; pcVar1 != (c2_symbol_cell *)0x0;
          pcVar1 = pcVar1->next) {
        if (pcVar1->sym == storage) {
          return 1;
        }
        if (pcVar1->sym == g_alias_special_symbol) {
          return 1;
        }
      }
    }
  }
  return 0;
}

