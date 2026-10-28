use std::{path::PathBuf, range::RangeInclusive};

#[derive(Debug, Clone, Copy)]
pub enum TokenVariant {
    String,
    Char,
    Int,
    Decimal,

    Typedef,
    Srtuct,
    Union,
    Enum,
    Trait,
    For,
    While,
    Impl,
    In,
    Var,

    Identifier,

    LeftParen,
    RightParen,
    LeftBrace,
    RightBrace,
    LeftAngle,
    RightAngle,

    Fullstop,
    Comma,
    Astresk,
    Ampersand,
    Slash,
    SemiColon,
    Colon,
    QuestionMark,
    Bang,
    Carrot,
    Percent,
    At,
    Hashtag,
    Doller,
    Plus,
    Minus,
    Equal,
    Pipe,
}

#[derive(Debug, Clone, Copy)]
pub struct Token {
    file_no: usize,
    range: RangeInclusive<usize>,
    variant: TokenVariant,
}

#[derive(Debug, Clone)]
pub struct File {
    path: PathBuf,
    contents: String,
}

#[derive(Debug, Clone)]
pub struct Module {
    files: Vec<File>,
    tokens: Vec<Token>,
}
