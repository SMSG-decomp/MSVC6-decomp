void __cdecl pch_relocate_vector_helper_tokens(void)

{
  token_io_release_record((int)g_vec_helper_prefix_tokens);
  token_io_release_record((int)g_vec_iterator_params_tokens);
  token_io_release_record((int)g_vec_ctor_iterator_body_tokens);
  token_io_release_record((int)g_vec_ctor_vb_body_tokens);
  token_io_release_record((int)g_vec_dtor_body_tokens);
  return;
}

