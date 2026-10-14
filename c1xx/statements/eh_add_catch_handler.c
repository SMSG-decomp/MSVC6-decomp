c1_catch_handler * __cdecl eh_add_catch_handler(c1_symbol *catch_param)

{
  void *pvVar1;
  c1_vector *v;
  c1_type *pcVar2;
  c1_type *pcVar3;
  uint uVar4;
  c1_u8 *rec;
  c1_catch_handler *rec_00;
  int iVar5;
  c1_symbol *pcVar6;
  c1_catchable_type *ct;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  short local_8;
  c1_catch_handler *prev_handler;
  
  if (catch_param != (c1_symbol *)0x0) {
    if ((((PTR_104d2cb8 != (c1_vector *)0x0) && (PTR_104d2cb8->count != 0)) &&
        (pvVar1 = PTR_104d2cb8->data[PTR_104d2cb8->count - 1], pvVar1 != (void *)0x0)) &&
       ((v = *(c1_vector **)((int)pvVar1 + 0xc), v != (c1_vector *)0x0 &&
        (*(char *)((int)pvVar1 + 0x14) != '\0')))) {
      rec_00 = arena_alloc(g_arenas + 4,0x24);
      if (rec_00 == (c1_catch_handler *)0x0) {
        rec_00 = (c1_catch_handler *)0x0;
      }
      else {
        eh_exception_type_init(rec_00,catch_param->type);
      }
      iVar5 = lex_line_number_of_position(&g_token_position);
      rec_00->position = iVar5;
      pcVar6 = rtti_type_descriptor_symbol((int)rec_00->object_type);
      rec_00->type_descriptor = pcVar6;
      rec_00->variable = catch_param;
      rec = g_arenas[4].cur;
      pcVar2 = rec_00->match_type;
      g_arenas[4].cur = g_arenas[4].cur + 0x44;
      if (g_arenas[4].end < g_arenas[4].cur) {
        arena_grow(g_arenas + 4);
      }
      ct = eh_catchable_type_init((c1_catchable_type *)rec,pcVar2,'\0');
      rec_00->catchable = ct;
      if ((((byte)ct->flags & 0xd) == 1) &&
         (uVar7 = eh_catchable_type_access_flags(ct,'\0'), (uVar7 & 0x20) != 0)) {
        diag_error(0x13c,rec_00->type);
      }
      local_8 = 0;
      do {
        while( true ) {
          while( true ) {
            while( true ) {
              iVar5 = (int)local_8;
              if ((int)(uint)v->count <= iVar5) {
                vector_push(v,rec_00);
                return rec_00;
              }
              local_8 = local_8 + 1;
              prev_handler = v->data[iVar5];
              pcVar2 = prev_handler->type;
              if (pcVar2 != (c1_type *)0x0) break;
              diag_error(0x137,rec_00->type,prev_handler->position);
            }
            pcVar3 = prev_handler->match_type;
            if (pcVar3 == rec_00->match_type) break;
            if (prev_handler->object_type == rec_00->match_type) {
              diag_error(0x139,rec_00->type,pcVar2,prev_handler->position);
            }
            else if (pcVar3 == rec_00->object_type) {
              diag_error(0x13b,rec_00->type,pcVar2,prev_handler->position);
            }
            else if (prev_handler->object_type == rec_00->object_type) {
              diag_error(0x138,rec_00->type,pcVar2,prev_handler->position);
            }
            else {
              uVar7 = rec_00->catchable->flags;
              uVar9 = uVar7 & 0xd;
              if (uVar9 != 0) {
                uVar4 = prev_handler->catchable->flags;
                uVar8 = uVar4 & 0xd;
                if ((uVar8 != 0) &&
                   (((((uVar4 ^ uVar7) & 0xd) == 0 ||
                     (((uVar9 != 4 && (uVar8 != 4)) && (uVar9 != 8)))) &&
                    (pcVar6 = class_lookup_qualified_member
                                        (g_current_scope,rec_00->catchable->cls,
                                         prev_handler->catchable->cls,0), pcVar6 != (c1_symbol *)0x0
                    )))) {
                  diag_warning(1,0x11e,rec_00->type,prev_handler->type,prev_handler->position);
                }
              }
            }
          }
          if (prev_handler->cv == 0) break;
          if (((rec_00->cv == 0) || ((prev_handler->cv & rec_00->cv) != 0)) ||
             (-1 < (char)pcVar3->code)) goto LAB_104ab740;
        }
      } while ((rec_00->cv != 0) && ((char)pcVar3->code < '\0'));
LAB_104ab740:
      diag_error(0x138,rec_00->type,prev_handler->type,prev_handler->position);
      return rec_00;
    }
    diag_error(0x13e);
  }
  return (c1_catch_handler *)0x0;
}

