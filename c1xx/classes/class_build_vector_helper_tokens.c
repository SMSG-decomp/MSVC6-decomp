void __cdecl class_build_vector_helper_tokens(void)

{
  c1xx_token_cursor *pcVar1;
  byte bVar2;
  int iVar3;
  c1xx_token_stream_vtbl *pcVar4;
  c1_u8 *pcVar5;
  int *piVar6;
  c1xx_token_stream *pcVar7;
  void *pvVar8;
  void *pvVar9;
  void *pvVar10;
  void *pvVar11;
  c1_u8 *token;
  c1_u8 *token_2;
  c1_u8 *token_3;
  c1_u8 *token_4;
  c1_u8 *pcVar12;
  c1_arena *pcVar13;
  int iVar14;
  uint *puVar15;
  uint *puVar16;
  uint *dst_4;
  uint *dst_3;
  uint *dst_2;
  uint *dst;
  
  if (g_vector_helper_tokens_built == '\0') {
    g_vector_helper_tokens_built = '\x01';
    piVar6 = arena_alloc(g_arenas,8);
    if (piVar6 == (int *)0x0) {
      piVar6 = (int *)0x0;
    }
    else {
      *piVar6 = g_token_arena_index;
      piVar6[1] = (int)g_token_arena_stack;
    }
    g_token_arena_index = 0;
    g_token_arena_stack = piVar6;
    pcVar7 = arena_alloc(g_arenas,0x38);
    iVar14 = g_token_position;
    if (pcVar7 == (c1xx_token_stream *)0x0) {
      g_vec_helper_prefix_tokens = (c1xx_token_stream *)0x0;
    }
    else {
      pcVar1 = &pcVar7->first;
      pcVar7->start_position = g_token_position;
      pcVar7->position = iVar14;
      token_buffer_init(pcVar1,0);
      pcVar7->arena = 0;
      pcVar7->vtbl = (c1xx_token_stream_vtbl *)&PTR_token_stream_next_raw_104bc55c;
      (pcVar7->read).chunk = pcVar1->chunk;
      (pcVar7->read).index = (pcVar7->first).index;
      (pcVar7->read).arena = (pcVar7->first).arena;
      iVar14 = (pcVar7->first).index;
      (pcVar7->write).chunk = pcVar1->chunk;
      iVar3 = (pcVar7->first).arena;
      (pcVar7->write).index = iVar14;
      (pcVar7->write).arena = iVar3;
      pcVar7->flags = pcVar7->flags & 0xfe;
      g_vec_helper_prefix_tokens = pcVar7;
    }
    pcVar7 = arena_alloc(g_arenas,0x38);
    iVar14 = g_token_position;
    if (pcVar7 == (c1xx_token_stream *)0x0) {
      g_vec_iterator_params_tokens = (c1xx_token_stream *)0x0;
    }
    else {
      pcVar1 = &pcVar7->first;
      pcVar7->start_position = g_token_position;
      pcVar7->position = iVar14;
      token_buffer_init(pcVar1,0);
      pcVar7->arena = 0;
      pcVar7->vtbl = (c1xx_token_stream_vtbl *)&PTR_token_stream_next_raw_104bc55c;
      (pcVar7->read).chunk = pcVar1->chunk;
      (pcVar7->read).index = (pcVar7->first).index;
      (pcVar7->read).arena = (pcVar7->first).arena;
      iVar14 = (pcVar7->first).index;
      (pcVar7->write).chunk = pcVar1->chunk;
      iVar3 = (pcVar7->first).arena;
      (pcVar7->write).index = iVar14;
      (pcVar7->write).arena = iVar3;
      pcVar7->flags = pcVar7->flags & 0xfe;
      g_vec_iterator_params_tokens = pcVar7;
    }
    pcVar7 = arena_alloc(g_arenas,0x38);
    iVar14 = g_token_position;
    if (pcVar7 == (c1xx_token_stream *)0x0) {
      g_vec_ctor_iterator_body_tokens = (c1xx_token_stream *)0x0;
    }
    else {
      pcVar1 = &pcVar7->first;
      pcVar7->start_position = g_token_position;
      pcVar7->position = iVar14;
      token_buffer_init(pcVar1,0);
      pcVar7->arena = 0;
      pcVar7->vtbl = (c1xx_token_stream_vtbl *)&PTR_token_stream_next_raw_104bc55c;
      (pcVar7->read).chunk = pcVar1->chunk;
      (pcVar7->read).index = (pcVar7->first).index;
      (pcVar7->read).arena = (pcVar7->first).arena;
      iVar14 = (pcVar7->first).index;
      (pcVar7->write).chunk = pcVar1->chunk;
      iVar3 = (pcVar7->first).arena;
      (pcVar7->write).index = iVar14;
      bVar2 = pcVar7->flags;
      (pcVar7->write).arena = iVar3;
      pcVar7->flags = bVar2 & 0xfe;
      g_vec_ctor_iterator_body_tokens = pcVar7;
    }
    pcVar7 = arena_alloc(g_arenas,0x38);
    iVar14 = g_token_position;
    if (pcVar7 == (c1xx_token_stream *)0x0) {
      g_vec_ctor_vb_body_tokens = (c1xx_token_stream *)0x0;
    }
    else {
      pcVar1 = &pcVar7->first;
      pcVar7->start_position = g_token_position;
      pcVar7->position = iVar14;
      token_buffer_init(pcVar1,0);
      pcVar7->arena = 0;
      pcVar7->vtbl = (c1xx_token_stream_vtbl *)&PTR_token_stream_next_raw_104bc55c;
      (pcVar7->read).chunk = pcVar1->chunk;
      (pcVar7->read).index = (pcVar7->first).index;
      (pcVar7->read).arena = (pcVar7->first).arena;
      iVar14 = (pcVar7->first).index;
      (pcVar7->write).chunk = pcVar1->chunk;
      iVar3 = (pcVar7->first).arena;
      (pcVar7->write).index = iVar14;
      (pcVar7->write).arena = iVar3;
      pcVar7->flags = pcVar7->flags & 0xfe;
      g_vec_ctor_vb_body_tokens = pcVar7;
    }
    pcVar7 = arena_alloc(g_arenas,0x38);
    iVar14 = g_token_position;
    if (pcVar7 == (c1xx_token_stream *)0x0) {
      g_vec_dtor_body_tokens = (c1xx_token_stream *)0x0;
    }
    else {
      pcVar1 = &pcVar7->first;
      pcVar7->start_position = g_token_position;
      pcVar7->position = iVar14;
      token_buffer_init(pcVar1,0);
      pcVar7->arena = 0;
      pcVar7->vtbl = (c1xx_token_stream_vtbl *)&PTR_token_stream_next_raw_104bc55c;
      (pcVar7->read).chunk = pcVar1->chunk;
      (pcVar7->read).index = (pcVar7->first).index;
      (pcVar7->read).arena = (pcVar7->first).arena;
      iVar14 = (pcVar7->first).index;
      (pcVar7->write).chunk = pcVar1->chunk;
      iVar3 = (pcVar7->first).arena;
      (pcVar7->write).index = iVar14;
      (pcVar7->write).arena = iVar3;
      pcVar7->flags = pcVar7->flags & 0xfe;
      g_vec_dtor_body_tokens = pcVar7;
    }
    pvVar8 = name_intern("__f");
    pvVar9 = name_intern("__n");
    pvVar10 = name_intern("__s");
    pvVar11 = name_intern("__t");
    (*g_vec_helper_prefix_tokens->vtbl->append)(g_vec_helper_prefix_tokens,(int)g_token_inline);
    (*g_vec_helper_prefix_tokens->vtbl->append)(g_vec_helper_prefix_tokens,(int)g_token_void);
    (*g_vec_helper_prefix_tokens->vtbl->append)(g_vec_helper_prefix_tokens,(int)g_token_stdcall);
    (*g_vec_iterator_params_tokens->vtbl->append)(g_vec_iterator_params_tokens,g_token_lparen);
    (*g_vec_iterator_params_tokens->vtbl->append)(g_vec_iterator_params_tokens,(int)g_token_void);
    (*g_vec_iterator_params_tokens->vtbl->append)(g_vec_iterator_params_tokens,(int)g_token_star);
    g_yylval = (uint)pvVar11;
    token = arena_or_pool_alloc(0x30,g_token_arena_index);
    if (token == (c1_u8 *)0x0) {
      token = (c1_u8 *)0x0;
    }
    else {
      *token = '\x06';
      puVar15 = &g_yylval;
      puVar16 = (uint *)(token + 8);
      for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
        *puVar16 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar16 = puVar16 + 1;
      }
    }
    (*g_vec_iterator_params_tokens->vtbl->append)(g_vec_iterator_params_tokens,(int)token);
    (*g_vec_iterator_params_tokens->vtbl->append)(g_vec_iterator_params_tokens,(int)g_token_comma);
    (*g_vec_iterator_params_tokens->vtbl->append)
              (g_vec_iterator_params_tokens,(int)g_token_unsigned);
    g_yylval = (uint)pvVar10;
    token_2 = arena_or_pool_alloc(0x30,g_token_arena_index);
    if (token_2 == (c1_u8 *)0x0) {
      token_2 = (c1_u8 *)0x0;
    }
    else {
      *token_2 = '\x06';
      puVar15 = &g_yylval;
      puVar16 = (uint *)(token_2 + 8);
      for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
        *puVar16 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar16 = puVar16 + 1;
      }
    }
    (*g_vec_iterator_params_tokens->vtbl->append)(g_vec_iterator_params_tokens,(int)token_2);
    (*g_vec_iterator_params_tokens->vtbl->append)(g_vec_iterator_params_tokens,(int)g_token_comma);
    (*g_vec_iterator_params_tokens->vtbl->append)(g_vec_iterator_params_tokens,(int)g_token_int);
    g_yylval = (uint)pvVar9;
    token_3 = arena_or_pool_alloc(0x30,g_token_arena_index);
    if (token_3 == (c1_u8 *)0x0) {
      token_3 = (c1_u8 *)0x0;
    }
    else {
      *token_3 = '\x06';
      puVar15 = &g_yylval;
      puVar16 = (uint *)(token_3 + 8);
      for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
        *puVar16 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar16 = puVar16 + 1;
      }
    }
    (*g_vec_iterator_params_tokens->vtbl->append)(g_vec_iterator_params_tokens,(int)token_3);
    (*g_vec_iterator_params_tokens->vtbl->append)(g_vec_iterator_params_tokens,(int)g_token_comma);
    pcVar4 = g_vec_iterator_params_tokens->vtbl;
    token_4 = token_new_decl_specifiers((int)g_type_void,0,(byte *)0x0,0);
    (*pcVar4->append)(g_vec_iterator_params_tokens,(int)token_4);
    (*g_vec_iterator_params_tokens->vtbl->append)(g_vec_iterator_params_tokens,g_token_lparen);
    (*g_vec_iterator_params_tokens->vtbl->append)
              (g_vec_iterator_params_tokens,(int)g_token_thiscall);
    (*g_vec_iterator_params_tokens->vtbl->append)(g_vec_iterator_params_tokens,(int)g_token_star);
    g_yylval = (uint)pvVar8;
    pcVar12 = arena_or_pool_alloc(0x30,g_token_arena_index);
    if (pcVar12 == (c1_u8 *)0x0) {
      pcVar12 = (c1_u8 *)0x0;
    }
    else {
      *pcVar12 = '\x06';
      puVar15 = &g_yylval;
      puVar16 = (uint *)(pcVar12 + 8);
      for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
        *puVar16 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar16 = puVar16 + 1;
      }
    }
    (*g_vec_iterator_params_tokens->vtbl->append)(g_vec_iterator_params_tokens,(int)pcVar12);
    (*g_vec_iterator_params_tokens->vtbl->append)(g_vec_iterator_params_tokens,g_token_rparen);
    (*g_vec_iterator_params_tokens->vtbl->append)(g_vec_iterator_params_tokens,g_token_lparen);
    (*g_vec_iterator_params_tokens->vtbl->append)(g_vec_iterator_params_tokens,(int)g_token_void);
    (*g_vec_iterator_params_tokens->vtbl->append)(g_vec_iterator_params_tokens,(int)g_token_star);
    (*g_vec_iterator_params_tokens->vtbl->append)(g_vec_iterator_params_tokens,g_token_rparen);
    (*g_vec_ctor_iterator_body_tokens->vtbl->append)
              (g_vec_ctor_iterator_body_tokens,(int)g_token_while);
    (*g_vec_ctor_iterator_body_tokens->vtbl->append)(g_vec_ctor_iterator_body_tokens,g_token_lparen)
    ;
    (*g_vec_ctor_iterator_body_tokens->vtbl->append)
              (g_vec_ctor_iterator_body_tokens,(int)g_token_minus_minus);
    g_yylval = (uint)pvVar9;
    pcVar12 = arena_or_pool_alloc(0x30,g_token_arena_index);
    if (pcVar12 == (c1_u8 *)0x0) {
      pcVar12 = (c1_u8 *)0x0;
    }
    else {
      *pcVar12 = '\x06';
      puVar15 = &g_yylval;
      puVar16 = (uint *)(pcVar12 + 8);
      for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
        *puVar16 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar16 = puVar16 + 1;
      }
    }
    (*g_vec_ctor_iterator_body_tokens->vtbl->append)(g_vec_ctor_iterator_body_tokens,(int)pcVar12);
    (*g_vec_ctor_iterator_body_tokens->vtbl->append)
              (g_vec_ctor_iterator_body_tokens,(int)g_token_greater_equal);
    _g_yylval_word2 = 0;
    g_yylval = (uint)g_type_int;
    _g_yylval_word3 = 0;
    pcVar12 = arena_or_pool_alloc(0x30,g_token_arena_index);
    if (pcVar12 == (c1_u8 *)0x0) {
      pcVar12 = (c1_u8 *)0x0;
    }
    else {
      *pcVar12 = 'e';
      puVar15 = &g_yylval;
      puVar16 = (uint *)(pcVar12 + 8);
      for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
        *puVar16 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar16 = puVar16 + 1;
      }
    }
    (*g_vec_ctor_iterator_body_tokens->vtbl->append)(g_vec_ctor_iterator_body_tokens,(int)pcVar12);
    (*g_vec_ctor_iterator_body_tokens->vtbl->append)(g_vec_ctor_iterator_body_tokens,g_token_rparen)
    ;
    (*g_vec_ctor_iterator_body_tokens->vtbl->append)
              (g_vec_ctor_iterator_body_tokens,(int)g_token_lbrace);
    (*g_vec_ctor_iterator_body_tokens->vtbl->append)(g_vec_ctor_iterator_body_tokens,g_token_lparen)
    ;
    (*g_vec_ctor_iterator_body_tokens->vtbl->append)
              (g_vec_ctor_iterator_body_tokens,(int)g_token_star);
    g_yylval = (uint)pvVar8;
    pcVar12 = arena_or_pool_alloc(0x30,g_token_arena_index);
    if (pcVar12 == (c1_u8 *)0x0) {
      pcVar12 = (c1_u8 *)0x0;
    }
    else {
      *pcVar12 = '\x06';
      puVar15 = &g_yylval;
      puVar16 = (uint *)(pcVar12 + 8);
      for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
        *puVar16 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar16 = puVar16 + 1;
      }
    }
    (*g_vec_ctor_iterator_body_tokens->vtbl->append)(g_vec_ctor_iterator_body_tokens,(int)pcVar12);
    (*g_vec_ctor_iterator_body_tokens->vtbl->append)(g_vec_ctor_iterator_body_tokens,g_token_rparen)
    ;
    (*g_vec_ctor_iterator_body_tokens->vtbl->append)(g_vec_ctor_iterator_body_tokens,g_token_lparen)
    ;
    g_yylval = (uint)pvVar11;
    pcVar12 = arena_or_pool_alloc(0x30,g_token_arena_index);
    if (pcVar12 == (c1_u8 *)0x0) {
      pcVar12 = (c1_u8 *)0x0;
    }
    else {
      *pcVar12 = '\x06';
      puVar15 = &g_yylval;
      puVar16 = (uint *)(pcVar12 + 8);
      for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
        *puVar16 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar16 = puVar16 + 1;
      }
    }
    (*g_vec_ctor_iterator_body_tokens->vtbl->append)(g_vec_ctor_iterator_body_tokens,(int)pcVar12);
    (*g_vec_ctor_iterator_body_tokens->vtbl->append)(g_vec_ctor_iterator_body_tokens,g_token_rparen)
    ;
    (*g_vec_ctor_iterator_body_tokens->vtbl->append)
              (g_vec_ctor_iterator_body_tokens,(int)g_token_semicolon);
    g_yylval = (uint)pvVar11;
    pcVar12 = arena_or_pool_alloc(0x30,g_token_arena_index);
    if (pcVar12 == (c1_u8 *)0x0) {
      pcVar12 = (c1_u8 *)0x0;
    }
    else {
      *pcVar12 = '\x06';
      puVar15 = &g_yylval;
      puVar16 = (uint *)(pcVar12 + 8);
      for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
        *puVar16 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar16 = puVar16 + 1;
      }
    }
    (*g_vec_ctor_iterator_body_tokens->vtbl->append)(g_vec_ctor_iterator_body_tokens,(int)pcVar12);
    (*g_vec_ctor_iterator_body_tokens->vtbl->append)
              (g_vec_ctor_iterator_body_tokens,(int)g_token_assign);
    (*g_vec_ctor_iterator_body_tokens->vtbl->append)(g_vec_ctor_iterator_body_tokens,g_token_lparen)
    ;
    (*g_vec_ctor_iterator_body_tokens->vtbl->append)
              (g_vec_ctor_iterator_body_tokens,(int)g_token_char);
    (*g_vec_ctor_iterator_body_tokens->vtbl->append)
              (g_vec_ctor_iterator_body_tokens,(int)g_token_star);
    (*g_vec_ctor_iterator_body_tokens->vtbl->append)(g_vec_ctor_iterator_body_tokens,g_token_rparen)
    ;
    if (g_token_arena_index == 0) {
      g_yylval = (uint)pvVar11;
      pcVar12 = pool_alloc_raw(&g_pool_default,0x30);
    }
    else {
      g_yylval = (uint)pvVar11;
      pcVar12 = arena_alloc(g_arenas + g_token_arena_index,0x30);
    }
    if (pcVar12 == (c1_u8 *)0x0) {
      pcVar12 = (c1_u8 *)0x0;
    }
    else {
      *pcVar12 = '\x06';
      puVar15 = &g_yylval;
      puVar16 = (uint *)(pcVar12 + 8);
      for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
        *puVar16 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar16 = puVar16 + 1;
      }
    }
    (*g_vec_ctor_iterator_body_tokens->vtbl->append)(g_vec_ctor_iterator_body_tokens,(int)pcVar12);
    (*g_vec_ctor_iterator_body_tokens->vtbl->append)
              (g_vec_ctor_iterator_body_tokens,(int)g_token_plus);
    if (g_token_arena_index == 0) {
      g_yylval = (uint)pvVar10;
      pcVar12 = pool_alloc_raw(&g_pool_default,0x30);
    }
    else {
      g_yylval = (uint)pvVar10;
      pcVar12 = arena_alloc(g_arenas + g_token_arena_index,0x30);
    }
    if (pcVar12 == (c1_u8 *)0x0) {
      pcVar12 = (c1_u8 *)0x0;
    }
    else {
      *pcVar12 = '\x06';
      puVar15 = &g_yylval;
      puVar16 = (uint *)(pcVar12 + 8);
      for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
        *puVar16 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar16 = puVar16 + 1;
      }
    }
    (*g_vec_ctor_iterator_body_tokens->vtbl->append)(g_vec_ctor_iterator_body_tokens,(int)pcVar12);
    (*g_vec_ctor_iterator_body_tokens->vtbl->append)
              (g_vec_ctor_iterator_body_tokens,(int)g_token_semicolon);
    (*g_vec_ctor_iterator_body_tokens->vtbl->append)
              (g_vec_ctor_iterator_body_tokens,(int)g_token_rbrace);
    (*g_vec_ctor_iterator_body_tokens->vtbl->append)
              (g_vec_ctor_iterator_body_tokens,(int)g_token_rbrace);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,(int)g_token_while);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,g_token_lparen);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,(int)g_token_minus_minus);
    if (g_token_arena_index == 0) {
      g_yylval = (uint)pvVar9;
      pcVar12 = pool_alloc_raw(&g_pool_default,0x30);
    }
    else {
      g_yylval = (uint)pvVar9;
      pcVar12 = arena_alloc(g_arenas + g_token_arena_index,0x30);
    }
    if (pcVar12 == (c1_u8 *)0x0) {
      pcVar12 = (c1_u8 *)0x0;
    }
    else {
      *pcVar12 = '\x06';
      puVar15 = &g_yylval;
      puVar16 = (uint *)(pcVar12 + 8);
      for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
        *puVar16 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar16 = puVar16 + 1;
      }
    }
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,(int)pcVar12);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,(int)g_token_greater_equal)
    ;
    _g_yylval_word2 = 0;
    _g_yylval_word3 = 0;
    g_yylval = (uint)g_type_int;
    if (g_token_arena_index == 0) {
      pcVar12 = pool_alloc_raw(&g_pool_default,0x30);
    }
    else {
      pcVar12 = arena_alloc(g_arenas + g_token_arena_index,0x30);
    }
    if (pcVar12 == (c1_u8 *)0x0) {
      pcVar12 = (c1_u8 *)0x0;
    }
    else {
      *pcVar12 = 'e';
      puVar15 = &g_yylval;
      puVar16 = (uint *)(pcVar12 + 8);
      for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
        *puVar16 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar16 = puVar16 + 1;
      }
    }
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,(int)pcVar12);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,g_token_rparen);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,(int)g_token_lbrace);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,g_token_lparen);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,(int)g_token_star);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,g_token_lparen);
    pcVar4 = g_vec_ctor_vb_body_tokens->vtbl;
    pcVar12 = token_new_decl_specifiers((int)g_type_void,0,(byte *)0x0,0);
    (*pcVar4->append)(g_vec_ctor_vb_body_tokens,(int)pcVar12);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,g_token_lparen);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,(int)g_token_thiscall);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,(int)g_token_star);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,g_token_rparen);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,g_token_lparen);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,(int)g_token_void);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,(int)g_token_star);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,(int)g_token_comma);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,(int)g_token_int);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,g_token_rparen);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,g_token_rparen);
    if (g_token_arena_index == 0) {
      g_yylval = (uint)pvVar8;
      pcVar12 = pool_alloc_raw(&g_pool_default,0x30);
    }
    else {
      g_yylval = (uint)pvVar8;
      pcVar12 = arena_alloc(g_arenas + g_token_arena_index,0x30);
    }
    if (pcVar12 == (c1_u8 *)0x0) {
      pcVar12 = (c1_u8 *)0x0;
    }
    else {
      *pcVar12 = '\x06';
      puVar15 = &g_yylval;
      puVar16 = (uint *)(pcVar12 + 8);
      for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
        *puVar16 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar16 = puVar16 + 1;
      }
    }
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,(int)pcVar12);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,g_token_rparen);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,g_token_lparen);
    if (g_token_arena_index == 0) {
      g_yylval = (uint)pvVar11;
      pcVar12 = pool_alloc_raw(&g_pool_default,0x30);
    }
    else {
      g_yylval = (uint)pvVar11;
      pcVar12 = arena_alloc(g_arenas + g_token_arena_index,0x30);
    }
    if (pcVar12 == (c1_u8 *)0x0) {
      pcVar12 = (c1_u8 *)0x0;
    }
    else {
      *pcVar12 = '\x06';
      puVar15 = &g_yylval;
      puVar16 = (uint *)(pcVar12 + 8);
      for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
        *puVar16 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar16 = puVar16 + 1;
      }
    }
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,(int)pcVar12);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,(int)g_token_comma);
    _g_yylval_word2 = 1;
    _g_yylval_word3 = 0;
    g_yylval = (uint)g_type_int;
    if (g_token_arena_index == 0) {
      pcVar12 = pool_alloc_raw(&g_pool_default,0x30);
    }
    else {
      pcVar12 = arena_alloc(g_arenas + g_token_arena_index,0x30);
    }
    if (pcVar12 == (c1_u8 *)0x0) {
      pcVar12 = (c1_u8 *)0x0;
    }
    else {
      *pcVar12 = 'e';
      puVar15 = &g_yylval;
      puVar16 = (uint *)(pcVar12 + 8);
      for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
        *puVar16 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar16 = puVar16 + 1;
      }
    }
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,(int)pcVar12);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,g_token_rparen);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,(int)g_token_semicolon);
    if (g_token_arena_index == 0) {
      g_yylval = (uint)pvVar11;
      pcVar12 = pool_alloc_raw(&g_pool_default,0x30);
    }
    else {
      g_yylval = (uint)pvVar11;
      pcVar12 = arena_alloc(g_arenas + g_token_arena_index,0x30);
    }
    if (pcVar12 == (c1_u8 *)0x0) {
      pcVar12 = (c1_u8 *)0x0;
    }
    else {
      *pcVar12 = '\x06';
      puVar15 = &g_yylval;
      puVar16 = (uint *)(pcVar12 + 8);
      for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
        *puVar16 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar16 = puVar16 + 1;
      }
    }
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,(int)pcVar12);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,(int)g_token_assign);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,g_token_lparen);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,(int)g_token_char);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,(int)g_token_star);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,g_token_rparen);
    if (g_token_arena_index == 0) {
      g_yylval = (uint)pvVar11;
      pcVar12 = pool_alloc_raw(&g_pool_default,0x30);
    }
    else {
      g_yylval = (uint)pvVar11;
      pcVar12 = arena_alloc(g_arenas + g_token_arena_index,0x30);
    }
    if (pcVar12 == (c1_u8 *)0x0) {
      pcVar12 = (c1_u8 *)0x0;
    }
    else {
      *pcVar12 = '\x06';
      puVar15 = &g_yylval;
      puVar16 = (uint *)(pcVar12 + 8);
      for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
        *puVar16 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar16 = puVar16 + 1;
      }
    }
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,(int)pcVar12);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,(int)g_token_plus);
    if (g_token_arena_index == 0) {
      g_yylval = (uint)pvVar10;
      pcVar12 = pool_alloc_raw(&g_pool_default,0x30);
    }
    else {
      g_yylval = (uint)pvVar10;
      pcVar12 = arena_alloc(g_arenas + g_token_arena_index,0x30);
    }
    if (pcVar12 == (c1_u8 *)0x0) {
      pcVar12 = (c1_u8 *)0x0;
    }
    else {
      *pcVar12 = '\x06';
      puVar15 = &g_yylval;
      puVar16 = (uint *)(pcVar12 + 8);
      for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
        *puVar16 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar16 = puVar16 + 1;
      }
    }
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,(int)pcVar12);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,(int)g_token_semicolon);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,(int)g_token_rbrace);
    (*g_vec_ctor_vb_body_tokens->vtbl->append)(g_vec_ctor_vb_body_tokens,(int)g_token_rbrace);
    if (g_token_arena_index == 0) {
      g_yylval = (uint)pvVar11;
      pcVar12 = pool_alloc_raw(&g_pool_default,0x30);
    }
    else {
      g_yylval = (uint)pvVar11;
      pcVar12 = arena_alloc(g_arenas + g_token_arena_index,0x30);
    }
    if (pcVar12 == (c1_u8 *)0x0) {
      pcVar12 = (c1_u8 *)0x0;
    }
    else {
      *pcVar12 = '\x06';
      puVar15 = &g_yylval;
      puVar16 = (uint *)(pcVar12 + 8);
      for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
        *puVar16 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar16 = puVar16 + 1;
      }
    }
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,(int)pcVar12);
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,(int)g_token_assign);
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,g_token_lparen);
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,(int)g_token_char);
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,(int)g_token_star);
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,g_token_rparen);
    if (g_token_arena_index == 0) {
      g_yylval = (uint)pvVar11;
      pcVar12 = pool_alloc_raw(&g_pool_default,0x30);
    }
    else {
      g_yylval = (uint)pvVar11;
      pcVar12 = arena_alloc(g_arenas + g_token_arena_index,0x30);
    }
    if (pcVar12 == (c1_u8 *)0x0) {
      pcVar12 = (c1_u8 *)0x0;
    }
    else {
      *pcVar12 = '\x06';
      puVar15 = &g_yylval;
      puVar16 = (uint *)(pcVar12 + 8);
      for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
        *puVar16 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar16 = puVar16 + 1;
      }
    }
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,(int)pcVar12);
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,(int)g_token_plus);
    if (g_token_arena_index == 0) {
      g_yylval = (uint)pvVar10;
      pcVar12 = pool_alloc_raw(&g_pool_default,0x30);
    }
    else {
      pcVar13 = g_arenas + g_token_arena_index;
      pcVar12 = pcVar13->cur;
      pcVar5 = g_arenas[g_token_arena_index].end;
      g_yylval = (uint)pvVar10;
      pcVar13->cur = pcVar12 + 0x30;
      if (pcVar5 < pcVar12 + 0x30) {
        arena_grow(pcVar13);
      }
    }
    if (pcVar12 == (c1_u8 *)0x0) {
      pcVar12 = (c1_u8 *)0x0;
    }
    else {
      *pcVar12 = '\x06';
      puVar15 = &g_yylval;
      puVar16 = (uint *)(pcVar12 + 8);
      for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
        *puVar16 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar16 = puVar16 + 1;
      }
    }
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,(int)pcVar12);
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,(int)g_token_star);
    if (g_token_arena_index == 0) {
      g_yylval = (uint)pvVar9;
      if (g_pool_default_left < 0x30) {
        pool_reserve((c1xx_pool *)&g_pool_default,0x30);
      }
      g_pool_default_left = g_pool_default_left - 0x30;
      pcVar12 = g_pool_default;
      g_pool_default = g_pool_default + 0x30;
    }
    else {
      g_yylval = (uint)pvVar9;
      pcVar12 = arena_alloc(g_arenas + g_token_arena_index,0x30);
    }
    if (pcVar12 == (c1_u8 *)0x0) {
      pcVar12 = (c1_u8 *)0x0;
    }
    else {
      *pcVar12 = '\x06';
      puVar15 = &g_yylval;
      puVar16 = (uint *)(pcVar12 + 8);
      for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
        *puVar16 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar16 = puVar16 + 1;
      }
    }
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,(int)pcVar12);
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,(int)g_token_semicolon);
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,(int)g_token_while);
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,g_token_lparen);
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,(int)g_token_minus_minus);
    if (g_token_arena_index == 0) {
      g_yylval = (uint)pvVar9;
      if (g_pool_default_left < 0x30) {
        pool_reserve((c1xx_pool *)&g_pool_default,0x30);
      }
      g_pool_default_left = g_pool_default_left - 0x30;
      pcVar12 = g_pool_default;
      g_pool_default = g_pool_default + 0x30;
    }
    else {
      g_yylval = (uint)pvVar9;
      pcVar12 = arena_alloc(g_arenas + g_token_arena_index,0x30);
    }
    if (pcVar12 == (c1_u8 *)0x0) {
      pcVar12 = (c1_u8 *)0x0;
    }
    else {
      *pcVar12 = '\x06';
      puVar15 = &g_yylval;
      puVar16 = (uint *)(pcVar12 + 8);
      for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
        *puVar16 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar16 = puVar16 + 1;
      }
    }
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,(int)pcVar12);
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,(int)g_token_greater_equal);
    _g_yylval_word2 = 0;
    _g_yylval_word3 = 0;
    g_yylval = (uint)g_type_int;
    if (g_token_arena_index == 0) {
      if (g_pool_default_left < 0x30) {
        pool_reserve((c1xx_pool *)&g_pool_default,0x30);
      }
      g_pool_default_left = g_pool_default_left - 0x30;
      pcVar12 = g_pool_default;
      g_pool_default = g_pool_default + 0x30;
    }
    else {
      pcVar12 = arena_alloc(g_arenas + g_token_arena_index,0x30);
    }
    if (pcVar12 == (c1_u8 *)0x0) {
      pcVar12 = (c1_u8 *)0x0;
    }
    else {
      *pcVar12 = 'e';
      puVar15 = &g_yylval;
      puVar16 = (uint *)(pcVar12 + 8);
      for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
        *puVar16 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar16 = puVar16 + 1;
      }
    }
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,(int)pcVar12);
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,g_token_rparen);
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,(int)g_token_lbrace);
    if (g_token_arena_index == 0) {
      g_yylval = (uint)pvVar11;
      if (g_pool_default_left < 0x30) {
        pool_reserve((c1xx_pool *)&g_pool_default,0x30);
      }
      g_pool_default_left = g_pool_default_left - 0x30;
      pcVar12 = g_pool_default;
      g_pool_default = g_pool_default + 0x30;
    }
    else {
      g_yylval = (uint)pvVar11;
      pcVar12 = arena_alloc(g_arenas + g_token_arena_index,0x30);
    }
    if (pcVar12 == (c1_u8 *)0x0) {
      pcVar12 = (c1_u8 *)0x0;
    }
    else {
      *pcVar12 = '\x06';
      puVar15 = &g_yylval;
      puVar16 = (uint *)(pcVar12 + 8);
      for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
        *puVar16 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar16 = puVar16 + 1;
      }
    }
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,(int)pcVar12);
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,(int)g_token_assign);
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,g_token_lparen);
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,(int)g_token_char);
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,(int)g_token_star);
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,g_token_rparen);
    if (g_token_arena_index == 0) {
      g_yylval = (uint)pvVar11;
      if (g_pool_default_left < 0x30) {
        pool_reserve((c1xx_pool *)&g_pool_default,0x30);
      }
      g_pool_default_left = g_pool_default_left - 0x30;
      pcVar12 = g_pool_default;
      g_pool_default = g_pool_default + 0x30;
    }
    else {
      pcVar13 = g_arenas + g_token_arena_index;
      pcVar12 = pcVar13->cur;
      pcVar5 = g_arenas[g_token_arena_index].end;
      g_yylval = (uint)pvVar11;
      pcVar13->cur = pcVar12 + 0x30;
      if (pcVar5 < pcVar12 + 0x30) {
        arena_grow(pcVar13);
      }
    }
    if (pcVar12 == (c1_u8 *)0x0) {
      pcVar12 = (c1_u8 *)0x0;
    }
    else {
      *pcVar12 = '\x06';
      puVar15 = &g_yylval;
      dst_4 = (uint *)(pcVar12 + 8);
      for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
        *dst_4 = *puVar15;
        puVar15 = puVar15 + 1;
        dst_4 = dst_4 + 1;
      }
    }
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,(int)pcVar12);
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,(int)g_token_minus);
    if (g_token_arena_index == 0) {
      g_yylval = (uint)pvVar10;
      if (g_pool_default_left < 0x30) {
        pool_reserve((c1xx_pool *)&g_pool_default,0x30);
      }
      g_pool_default_left = g_pool_default_left - 0x30;
      pcVar12 = g_pool_default;
      g_pool_default = g_pool_default + 0x30;
    }
    else {
      pcVar13 = g_arenas + g_token_arena_index;
      pcVar12 = pcVar13->cur;
      pcVar5 = g_arenas[g_token_arena_index].end;
      g_yylval = (uint)pvVar10;
      pcVar13->cur = pcVar12 + 0x30;
      if (pcVar5 < pcVar12 + 0x30) {
        arena_grow(pcVar13);
      }
    }
    if (pcVar12 == (c1_u8 *)0x0) {
      pcVar12 = (c1_u8 *)0x0;
    }
    else {
      *pcVar12 = '\x06';
      puVar15 = &g_yylval;
      dst_3 = (uint *)(pcVar12 + 8);
      for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
        *dst_3 = *puVar15;
        puVar15 = puVar15 + 1;
        dst_3 = dst_3 + 1;
      }
    }
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,(int)pcVar12);
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,(int)g_token_semicolon);
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,g_token_lparen);
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,(int)g_token_star);
    if (g_token_arena_index == 0) {
      g_yylval = (uint)pvVar8;
      if (g_pool_default_left < 0x30) {
        pool_reserve((c1xx_pool *)&g_pool_default,0x30);
      }
      g_pool_default_left = g_pool_default_left - 0x30;
      pcVar12 = g_pool_default;
      g_pool_default = g_pool_default + 0x30;
    }
    else {
      pcVar13 = g_arenas + g_token_arena_index;
      pcVar12 = pcVar13->cur;
      pcVar5 = g_arenas[g_token_arena_index].end;
      g_yylval = (uint)pvVar8;
      pcVar13->cur = pcVar12 + 0x30;
      if (pcVar5 < pcVar12 + 0x30) {
        arena_grow(pcVar13);
      }
    }
    if (pcVar12 == (c1_u8 *)0x0) {
      pcVar12 = (c1_u8 *)0x0;
    }
    else {
      *pcVar12 = '\x06';
      puVar15 = &g_yylval;
      dst_2 = (uint *)(pcVar12 + 8);
      for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
        *dst_2 = *puVar15;
        puVar15 = puVar15 + 1;
        dst_2 = dst_2 + 1;
      }
    }
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,(int)pcVar12);
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,g_token_rparen);
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,g_token_lparen);
    if (g_token_arena_index == 0) {
      g_yylval = (uint)pvVar11;
      if (g_pool_default_left < 0x30) {
        pool_reserve((c1xx_pool *)&g_pool_default,0x30);
      }
      g_pool_default_left = g_pool_default_left - 0x30;
      pcVar12 = g_pool_default;
      g_pool_default = g_pool_default + 0x30;
    }
    else {
      pcVar13 = g_arenas + g_token_arena_index;
      pcVar12 = pcVar13->cur;
      pcVar5 = g_arenas[g_token_arena_index].end;
      g_yylval = (uint)pvVar11;
      pcVar13->cur = pcVar12 + 0x30;
      if (pcVar5 < pcVar12 + 0x30) {
        arena_grow(pcVar13);
      }
    }
    if (pcVar12 == (c1_u8 *)0x0) {
      pcVar12 = (c1_u8 *)0x0;
    }
    else {
      *pcVar12 = '\x06';
      puVar15 = &g_yylval;
      dst = (uint *)(pcVar12 + 8);
      for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
        *dst = *puVar15;
        puVar15 = puVar15 + 1;
        dst = dst + 1;
      }
    }
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,(int)pcVar12);
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,g_token_rparen);
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,(int)g_token_semicolon);
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,(int)g_token_rbrace);
    (*g_vec_dtor_body_tokens->vtbl->append)(g_vec_dtor_body_tokens,(int)g_token_rbrace);
    g_token_arena_index = *g_token_arena_stack;
    g_token_arena_stack = (int *)g_token_arena_stack[1];
  }
  return;
}

