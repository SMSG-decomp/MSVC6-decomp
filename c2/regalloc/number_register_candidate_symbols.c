uint32_t __fastcall number_register_candidate_symbols(uint32_t next_id)

{
  uint16_t type;
  c2_symbol *pcVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  c2_bitset *pcVar6;
  c2_symbol *pcVar7;
  ushort uVar8;
  int iVar9;
  c2_ra_candidate *group_rec;
  c2_ra_candidate *pcVar10;
  c2_symbol *pcVar11;
  c2_symbol *pcVar12;
  c2_bitset *local_18;
  uint32_t local_10;
  c2_symbol *local_c;
  c2_symbol_chunk *local_4;
  
  local_18 = (c2_bitset *)0x0;
  local_4 = g_symbol_chunks;
  local_10 = next_id;
  if (g_symbol_chunks == (c2_symbol_chunk *)0x0) {
    return next_id;
  }
  do {
    pcVar11 = local_4->syms;
    if (pcVar11 < local_4->cursor) {
      do {
        if ((pcVar11->cls != '\x10') && (pcVar11->storage == pcVar11)) {
          bVar5 = false;
          pcVar1 = pcVar11;
          pcVar6 = local_18;
          switch(pcVar11->cls) {
          case '\x03':
            if (pcVar11->def != (c2_tuple *)0x0) goto switchD_1071ab96_caseD_6;
            pcVar11->flags6 = pcVar11->flags6 & 0xfd;
            goto joined_r0x1071abc7;
          case '\x04':
          case '\x05':
            if ((pcVar11->flags5 & 2) == 0) goto joined_r0x1071abc7;
          case '\a':
          case '\b':
            bVar5 = true;
joined_r0x1071abc7:
            for (; local_18 = pcVar6, pcVar1 != (c2_symbol *)0x0; pcVar1 = pcVar1->part_next) {
              type = pcVar1->type;
              (pcVar1->u34).refs = 0;
              iVar9 = type_is_register_candidate(type);
              if ((iVar9 == 0) || (((type & 0xf000) == 0x4000 && (g_opt_float_consistency != 0)))) {
                (pcVar1->u30).order_prev = (c2_symbol *)0x0;
              }
              else {
                if ((pcVar1->size < 4) &&
                   (((pcVar1->size < pcVar11->size || (pcVar1->cls == '\x03')) &&
                    ((pcVar11->flags5 & 0x80) == 0)))) {
                  local_c = (c2_symbol *)0x0;
                  pcVar12 = pcVar11;
                  do {
                    pcVar7 = local_c;
                    if (pcVar12 != pcVar1) {
                      uVar8 = pcVar12->type;
                      iVar9 = type_is_register_candidate(uVar8);
                      if (((iVar9 != 0) && (uVar8 = uVar8 & 0xf000, uVar8 != 0x4000)) &&
                         (uVar8 != 0xa000)) {
                        iVar9 = pcVar12->offset;
                        iVar2 = pcVar1->offset;
                        if ((((iVar9 <= iVar2) &&
                             (iVar3 = pcVar12->size, pcVar1->size + iVar2 <= iVar3 + iVar9)) &&
                            ((pcVar1->size < iVar3 &&
                             (((iVar2 == iVar9 || ((iVar2 == iVar9 + 1 && (pcVar1->size == 1)))) &&
                              (pcVar7 = pcVar12, local_c != (c2_symbol *)0x0)))))) &&
                           (iVar3 <= local_c->size)) {
                          pcVar7 = local_c;
                        }
                      }
                    }
                    local_c = pcVar7;
                    pcVar12 = pcVar12->part_next;
                  } while (pcVar12 != (c2_symbol *)0x0);
                  next_id = local_10;
                  if (local_c != (c2_symbol *)0x0) {
                    (pcVar1->u30).order_prev = (c2_symbol *)0x0;
                    (pcVar1->u34).parent = local_c;
                    goto LAB_1071ac16;
                  }
                }
                if (bVar5) {
                  if (pcVar6 == (c2_bitset *)0x0) {
                    local_18 = bitset_new(6);
                  }
                  bitset_set(local_18,next_id);
                }
                pcVar10 = arena_alloc(4,0x18);
                pcVar10->id = next_id;
                local_10 = next_id + 1;
                (pcVar1->u30).ra = pcVar10;
                next_id = local_10;
              }
LAB_1071ac16:
              pcVar6 = local_18;
            }
            if (pcVar6 != (c2_bitset *)0x0) {
              if ((pcVar11->u30).order_prev == (c2_symbol *)0x0) {
                group_rec = arena_alloc(4,0x18);
                (pcVar11->u30).ra = group_rec;
              }
              local_18 = (c2_bitset *)0x0;
              ((pcVar11->u30).ra)->part_ids = pcVar6;
            }
            pcVar11->flags5 = pcVar11->flags5 & 0x7f;
            break;
          case '\n':
            uVar4 = pcVar11->fe->storage;
            if (((uVar4 & 0x1000) != 0) && ((uVar4 & 0x4000) == 0)) {
              for (; pcVar1 != (c2_symbol *)0x0; pcVar1 = pcVar1->part_next) {
                if (pcVar1->size == 4) {
                  pcVar10 = arena_alloc(4,0x18);
                  pcVar10->id = next_id;
                  next_id = next_id + 1;
                  (pcVar1->u30).ra = pcVar10;
                  (pcVar1->u34).refs = 0;
                }
                else {
                  (pcVar1->u30).order_prev = (c2_symbol *)0x0;
                  (pcVar1->u34).refs = 0;
                }
                local_10 = next_id;
              }
              break;
            }
          default:
switchD_1071ab96_caseD_6:
            for (; pcVar1 != (c2_symbol *)0x0; pcVar1 = pcVar1->part_next) {
              (pcVar1->u30).order_prev = (c2_symbol *)0x0;
              (pcVar1->u34).refs = 0;
            }
          }
        }
        pcVar11 = pcVar11 + 1;
      } while (pcVar11 < local_4->cursor);
    }
    local_4 = local_4->next;
    if (local_4 == (c2_symbol_chunk *)0x0) {
      return next_id;
    }
  } while( true );
}

