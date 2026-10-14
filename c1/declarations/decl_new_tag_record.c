c1_token * __cdecl decl_new_tag_record(ushort kind,c1_specifier_words *storage)

{
  byte *pbVar1;
  c1_u8 cVar2;
  c1_token *pcVar3;
  c1_tag_record *tag;
  c1_u8 token_class;
  
  tag = (c1_tag_record *)g_arenas[3].cur;
  g_arenas[3].cur = g_arenas[3].cur + 0x28;
  if (g_arenas[3].end < g_arenas[3].cur) {
    arena_grow(g_arenas + 3);
  }
  if (tag == (c1_tag_record *)0x0) {
    tag = (c1_tag_record *)0x0;
  }
  else {
    *(c1_specifier_words **)((int)tag + 0x1c) = storage;
    pbVar1 = (byte *)((int)tag + 0x10);
    *(uchar *)((int)tag + 0) = '\0';
    *(uchar *)((int)tag + 1) = '\0';
    *(uchar *)((int)tag + 2) = '\0';
    *(uchar *)((int)tag + 3) = '\0';
    *(uchar *)((int)tag + 4) = '\0';
    *(uchar *)((int)tag + 5) = '\0';
    *(uchar *)((int)tag + 6) = '\0';
    *(uchar *)((int)tag + 7) = '\0';
    *(uchar *)((int)tag + 8) = '\0';
    *(uchar *)((int)tag + 9) = '\0';
    *(uchar *)((int)tag + 10) = '\0';
    *(uchar *)((int)tag + 0xb) = '\0';
    *(ushort *)((int)tag + 0xc) = kind;
    *(uchar *)((int)tag + 0xe) = '\0';
    *(uchar *)((int)tag + 0xf) = '\0';
    *pbVar1 = *pbVar1 & 0xf8;
    pbVar1[0] = 0;
    pbVar1[1] = 0;
    pbVar1[2] = 0;
    pbVar1[3] = 0;
    *(uchar *)((int)tag + 0x14) = '\0';
    *(uchar *)((int)tag + 0x15) = '\0';
    *(uchar *)((int)tag + 0x16) = '\0';
    *(uchar *)((int)tag + 0x17) = '\0';
    *(uchar *)((int)tag + 0x18) = '\0';
    *(uchar *)((int)tag + 0x19) = '\0';
    *(uchar *)((int)tag + 0x1a) = '\0';
    *(uchar *)((int)tag + 0x1b) = '\0';
    *pbVar1 = *pbVar1 & 7 ^ *pbVar1;
    *(uchar *)((int)tag + 0x20) = '\0';
    *(uchar *)((int)tag + 0x21) = '\0';
    *(uchar *)((int)tag + 0x22) = '\0';
    *(uchar *)((int)tag + 0x23) = '\0';
    *(uchar *)((int)tag + 0x24) = '\x01';
  }
  pcVar3 = token_next(&g_token_position);
  token_class = (&g_token_class)[pcVar3->code];
  do {
    switch(token_class) {
    case '\0':
      diag_fatal_simple(4);
    default:
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar3);
LAB_1060ed02:
      pcVar3 = type_check_tag_kind(tag,pcVar3);
      return pcVar3;
    case '\x06':
      cVar2 = decl_tag_take_name(tag,pcVar3);
      if (cVar2 == '\0') goto LAB_1060ed02;
      break;
    case 'u':
      pcVar3 = type_check_tag_kind_2(tag,pcVar3);
      return pcVar3;
    case '\x7f':
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar3);
      pcVar3 = type_check_tag_kind(tag,pcVar3);
      return pcVar3;
    case 0xba:
      cVar2 = decl_tag_parse_declspec(tag);
      if (cVar2 == '\0') {
        (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar3);
        pcVar3 = type_check_tag_kind(tag,pcVar3);
        return pcVar3;
      }
    }
    pcVar3 = token_next(&g_token_position);
    token_class = (&g_token_class)[pcVar3->code];
  } while( true );
}

