c2_list_cell * __cdecl move_zero_initialized_data_to_bss(void)

{
  byte bVar1;
  c2_fe_symbol *pcVar2;
  int iVar3;
  uint uVar4;
  c2_list_cell *pcVar5;
  c2_init *rec;
  c2_list_cell *list_tail;
  c2_list_cell *list_head;
  c2_init *hdr;
  
  g_incr_skip_known_globals = 1;
  hdr = g_init_record_list;
  do {
    if (hdr == (c2_init *)0x0) {
      list_tail = (c2_list_cell *)&list_head;
      list_head = (c2_list_cell *)0x0;
      pcVar5 = list_head;
      hdr = g_init_record_list;
      do {
        list_head = pcVar5;
        if (hdr == (c2_init *)0x0) {
          empty_hook();
          g_incr_skip_known_globals = 0;
          return pcVar5;
        }
        if (((hdr->u08).header.placed == 0) &&
           ((pcVar2 = (hdr->u18).sym, pcVar2 != (c2_fe_symbol *)0x0 ||
            (pcVar2 = fe_symbol_lookup_id((hdr->u08).header.sym_id), pcVar2 != (c2_fe_symbol *)0x0))
           )) {
          if (((pcVar2->cls == '\x04') || (pcVar2->cls == '\x01')) &&
             ((pcVar2->storage & 0x1000) != 0)) {
            pcVar2 = (c2_fe_symbol *)fe_symbol_resolve_redirect((int)pcVar2);
          }
          if (((pcVar2->flags31 & 4) == 4) && ((pcVar2->flags31 & 3) == 0)) {
            uVar4 = pcVar2->storage & 0x780;
            if (((uVar4 == 0x80) || (uVar4 == 0x200)) &&
               (((((byte)pcVar2->storage & 0x70) != 0x40 &&
                 (uVar4 = pcVar2->attrs, (uVar4 & 0x1200) == 0)) && (g_opt_bzalign == 0)))) {
              rec = hdr->next;
              if (rec != (c2_init *)0x0) {
LAB_10741218:
                switch(rec->kind) {
                case 1:
                case 0x10:
                  iVar3 = init_record_is_zero(rec);
                  if (iVar3 != 0) goto switchD_10741228_caseD_4;
                  break;
                case 4:
                case 8:
                  goto switchD_10741228_caseD_4;
                }
                if (rec != (c2_init *)0x0) goto LAB_10741247;
              }
LAB_1074126b:
              pcVar2->attrs = uVar4 & 0xfffffb7f;
              pcVar2->section_id = 0;
              fe_symbol_choose_section(pcVar2);
              fe_symbol_assign_frame(pcVar2);
              (hdr->u08).header.placed = 1;
            }
            else {
LAB_10741247:
              pcVar5 = alloc_8_arena4();
              pcVar5->next = (c2_list_cell *)0x0;
              (pcVar5->u04).fe = pcVar2;
              list_tail->next = pcVar5;
              list_tail = pcVar5;
            }
          }
        }
        hdr = (hdr->u08).header.list_next;
        pcVar5 = list_head;
      } while( true );
    }
    if ((hdr->u08).header.placed == 0) {
      pcVar2 = (hdr->u18).sym;
      if (pcVar2 == (c2_fe_symbol *)0x0) {
        pcVar2 = fe_symbol_lookup_id((hdr->u08).header.sym_id);
        if (pcVar2 == (c2_fe_symbol *)0x0) goto LAB_107410f2;
        (hdr->u18).sym = pcVar2;
      }
      if (((pcVar2->cls == '\x04') || (pcVar2->cls == '\x01')) && ((pcVar2->storage & 0x1000) != 0))
      {
        pcVar2 = (c2_fe_symbol *)fe_symbol_resolve_redirect((int)pcVar2);
      }
      bVar1 = pcVar2->flags31;
      if (((bVar1 & 1) != 1) && ((bVar1 & 2) != 2)) {
        if ((bVar1 & 4) == 0) {
          if (((byte)pcVar2->attrs & 0x60) != 0x20) {
            pcVar2->flags31 = bVar1 | 4;
            iVar3 = mark_initialiser_dependencies(pcVar2);
            if (iVar3 != 0) {
              pcVar2->flags31 = pcVar2->flags31 & 0xfb;
              goto LAB_107410eb;
            }
            pcVar2->flags31 = pcVar2->flags31 & 0xfb;
          }
        }
        else {
LAB_107410eb:
          note_symbol_and_initialisers(pcVar2);
        }
      }
    }
LAB_107410f2:
    hdr = (hdr->u08).header.list_next;
  } while( true );
switchD_10741228_caseD_4:
  rec = rec->next;
  if (rec == (c2_init *)0x0) goto LAB_1074126b;
  goto LAB_10741218;
}

