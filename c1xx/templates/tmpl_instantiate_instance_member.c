char __cdecl
tmpl_instantiate_instance_member(c1_symbol *instance,c1_symbol *member,char explicit_inst)

{
  c1_symbol *sym;
  bool bVar1;
  c1_sym_link *pcVar2;
  c1_symbol *pcVar3;
  byte bVar4;
  c1_symbol *cls;
  c1_arg_list *inst_args;
  c1_keyed_list *pcVar5;
  int iVar6;
  c1_symbol *entry_sym_6;
  c1_symbol *entry_sym_4;
  c1_symbol *entry_sym;
  c1_symbol *entry_sym_5;
  c1_symbol *entry_sym_3;
  c1_symbol *set;
  c1_symbol *entry_sym_2;
  fe_name **ppfVar7;
  fe_name **ppfVar8;
  c1_sym_link *inst_link;
  fe_name *name;
  fe_name *name_00;
  c1_sym_link *inst_next;
  c1_sym_link *tmpl_next;
  c1_sym_link *tmpl_link;
  
  cls = tmpl_template_of_instance(instance);
  if ((cls->flags3 & 4) == 0) {
    inst_args = symtab_15f4_lookup(instance);
    name_00 = member->name;
    name = name_00;
    if (((member->flags1 & 0x40) == 0) ||
       (pcVar5 = class_lookup_member_name(cls,name_00,2), name = g_name_unnamed,
       pcVar5 == (c1_keyed_list *)0x0)) {
      pcVar5 = class_lookup_member_name_thunk(cls,name,2);
      name_00 = name;
    }
    set = pcVar5->head->sym;
    bVar4 = set->kind & 0x1f;
    if (bVar4 == 0x11) {
      if ((member->flags1 & 0x40) == 0) {
        pcVar5 = class_lookup_member_name_thunk(instance,name_00,2);
        ppfVar8 = &set->name;
        tmpl_next = (c1_sym_link *)(c1_type *)0x0;
        if (((ppfVar8 != (fe_name **)0x0) &&
            (iVar6 = sym_is_data_or_function_2(set), tmpl_next = (c1_sym_link *)ppfVar8,
            (char)iVar6 == '\0')) && ((set->kind & 0x1f) != 0x1a)) {
          tmpl_next = (c1_sym_link *)set->type;
        }
        sym = pcVar5->head->sym;
        ppfVar7 = &sym->name;
        inst_link = (c1_sym_link *)(c1_symbol *)0x0;
        if (((ppfVar7 != (fe_name **)0x0) &&
            (iVar6 = sym_is_data_or_function_2(sym), inst_link = (c1_sym_link *)ppfVar7,
            (char)iVar6 == '\0')) && ((sym->kind & 0x1f) != 0x1a)) {
          inst_link = (c1_sym_link *)sym->type;
        }
        do {
          if (ppfVar8 == (fe_name **)0x0) {
            return '\0';
          }
          if ((c1_type *)tmpl_next == (c1_type *)0x0) {
            return '\0';
          }
          iVar6 = sym_is_data_or_function_2(set);
          if (((char)iVar6 == '\0') && ((set->kind & 0x1f) != 0x1a)) {
            entry_sym_2 = (c1_symbol *)((c1_type *)tmpl_next)->base;
          }
          else {
            entry_sym_2 = (c1_symbol *)0x0;
          }
          if (ppfVar7 == (fe_name **)0x0) {
            return '\0';
          }
          if ((c1_symbol *)inst_link == (c1_symbol *)0x0) {
            return '\0';
          }
          iVar6 = sym_is_data_or_function_2(sym);
          if (((char)iVar6 == '\0') && ((sym->kind & 0x1f) != 0x1a)) {
            inst_next = *(c1_sym_link **)&((c1_symbol *)inst_link)->flags4;
            pcVar3 = entry_sym_2;
            tmpl_link = (c1_sym_link *)(c1_type *)tmpl_next;
          }
          else {
            inst_next = (c1_sym_link *)0x0;
            pcVar3 = entry_sym_2;
            tmpl_link = tmpl_next;
          }
          while( true ) {
            tmpl_next = (c1_sym_link *)pcVar3;
            pcVar2 = tmpl_next;
            entry_sym_6 = (c1_symbol *)&tmpl_link[-1].position;
            if ((tmpl_link[-1].position & 0x1f) == 0x1a) {
              entry_sym_6 = ((tmpl_link->type).alias)->target;
            }
            if ((*(byte *)((int)&entry_sym_6->tail + 9) & 0x20) == 0) break;
            if (tmpl_next == (c1_sym_link *)0x0) {
              return '\0';
            }
            iVar6 = sym_is_data_or_function_2(set);
            tmpl_link = pcVar2;
            if (((char)iVar6 == '\0') && ((set->kind & 0x1f) != 0x1a)) {
              pcVar3 = (c1_symbol *)tmpl_next->next;
            }
            else {
              tmpl_next = (c1_sym_link *)0x0;
              pcVar3 = (c1_symbol *)tmpl_next;
            }
          }
          do {
            bVar1 = true;
            while( true ) {
              entry_sym_4 = (c1_symbol *)((int)&((c1_symbol *)((int)inst_link + -0x38))->tail + 4);
              if ((*(byte *)((int)&((c1_symbol *)((int)inst_link + -0x38))->tail + 4) & 0x1f) ==
                  0x1a) {
                entry_sym_4 = *(c1_symbol **)((c1_symbol *)inst_link)->next;
              }
              if ((entry_sym_4->flags3 & 1) == 0) break;
              bVar1 = false;
              if ((c1_symbol *)inst_next == (c1_symbol *)0x0) {
                return '\0';
              }
              iVar6 = sym_is_data_or_function_2(sym);
              inst_link = inst_next;
              if (((char)iVar6 == '\0') && ((sym->kind & 0x1f) != 0x1a)) {
                inst_next = (c1_sym_link *)*(c1_symbol **)&((c1_symbol *)inst_next)->flags4;
              }
              else {
                inst_next = (c1_sym_link *)(c1_symbol *)0x0;
              }
            }
            while( true ) {
              entry_sym = (c1_symbol *)((int)&((c1_symbol *)((int)inst_link + -0x38))->tail + 4);
              if ((*(byte *)((int)&((c1_symbol *)((int)inst_link + -0x38))->tail + 4) & 0x1f) ==
                  0x1a) {
                entry_sym = *(c1_symbol **)((c1_symbol *)inst_link)->next;
              }
              if ((*(byte *)((int)&entry_sym->tail + 9) & 0x20) == 0) break;
              bVar1 = false;
              if ((c1_symbol *)inst_next == (c1_symbol *)0x0) {
                return '\0';
              }
              iVar6 = sym_is_data_or_function_2(sym);
              inst_link = inst_next;
              if (((char)iVar6 == '\0') && ((sym->kind & 0x1f) != 0x1a)) {
                inst_next = (c1_sym_link *)*(c1_symbol **)&((c1_symbol *)inst_next)->flags4;
              }
              else {
                inst_next = (c1_sym_link *)(c1_symbol *)0x0;
              }
            }
            while( true ) {
              entry_sym_5 = (c1_symbol *)&inst_link[-1].position;
              if ((inst_link[-1].position & 0x1f) == 0x1a) {
                entry_sym_5 = ((inst_link->type).alias)->target;
              }
              if ((*(byte *)((int)&entry_sym_5->tail + 9) & 0x40) == 0) break;
              bVar1 = false;
              if ((c1_symbol *)inst_next == (c1_symbol *)0x0) {
                return '\0';
              }
              iVar6 = sym_is_data_or_function_2(sym);
              if (((char)iVar6 == '\0') && ((sym->kind & 0x1f) != 0x1a)) {
                inst_link = inst_next;
                inst_next = (c1_sym_link *)*(c1_symbol **)&((c1_symbol *)inst_next)->flags4;
              }
              else {
                inst_link = inst_next;
                inst_next = (c1_sym_link *)(c1_symbol *)0x0;
              }
            }
          } while (!bVar1);
          entry_sym_3 = (c1_symbol *)&inst_link[-1].position;
          if ((inst_link[-1].position & 0x1f) == 0x1a) {
            entry_sym_3 = ((inst_link->type).alias)->target;
          }
          inst_link = inst_next;
        } while (entry_sym_3 != member);
        set = (c1_symbol *)&tmpl_link[-1].position;
        if ((tmpl_link[-1].position & 0x1f) == 0x1a) {
          set = ((tmpl_link->type).alias)->target;
        }
      }
      else {
        set = tmpl_find_overload_by_signature(set,member,inst_args);
      }
      if (set == (c1_symbol *)0x0) {
        return '\0';
      }
    }
    else if (bVar4 != 8) {
      member = sym_static_member_stand_in(member);
    }
    if ((set->flags2 & 4) != 0) {
      member->storage = member->storage | 0x40;
      if ((explicit_inst != '\0') && ((member->flags22 & 8) == 0)) {
        member->flags21 = member->flags21 | 0x80;
      }
      bVar4 = member->kind & 0x1f;
      if (((bVar4 == 7) || (bVar4 == 8)) && ((member->flags21 & 1) == 0)) {
        member->flags21 = member->flags21 | 1;
      }
      tmpl_instantiate_member(cls,instance,set,(int *)inst_args,member);
      return '\x01';
    }
    if (explicit_inst != '\0') {
      diag_warning(1,0x295,member);
    }
  }
  return '\0';
}

