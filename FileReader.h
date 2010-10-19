//
//  FileReader.h
//  LineReader
//
//  Created by Tobias Preuss on 05.10.10.
//  Copyright 2010 Tobias Preuss. All rights reserved.
//
//  Originally written by Dave DeLong, 
//  Source: http://stackoverflow.com/questions/3707427#3711079

#import <Cocoa/Cocoa.h>


@interface FileReader : NSObject {
	
	NSString*			m_filePath;				/**< File path. */
	NSFileHandle*		m_fileHandle;			/**< File handle. */
	unsigned long long	m_currentOffset;		/**< Current offset is needed for forwards reading. */
	unsigned long long	m_currentIndent;		/**< Current indent is needed for backwards reading. */
	NSRange				m_prevDelimiterRange;	/**< Position and length of the last delimiter. */	
	unsigned long long	m_totalFileLength;		/**< Total number of bytes in file. */
	NSString*			m_lineDelimiter;		/**< Character for line break or page break. */
	NSUInteger			m_chunkSize;			/**< Standard block size. */
}

@property (readwrite, assign) unsigned long long currentOffset;		/**< Property for the current offset. */
@property (readwrite, assign) unsigned long long currentIndent;		/**< Property for the current indent. */

- (id)initWithFilePath:(NSString*)filePath;
- (NSString*)readLine;
- (NSString*)readLineBackwards;
- (NSString*)readTrimmedLine;
- (void)closeFileHandle;

#if NS_BLOCKS_AVAILABLE
- (void)enumerateLinesUsingBlock:(void(^)(NSString*, BOOL*))block;
#endif

@end