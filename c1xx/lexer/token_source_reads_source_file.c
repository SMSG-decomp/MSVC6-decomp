c1_u8 __fastcall token_source_reads_source_file(c1_token_reader *reader)

{
  return reader->top->stream->flags & 1;
}

